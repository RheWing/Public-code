#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FOR(a, i, j) for(int a = i; a <= j; a++)
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);

const ll INF = 1e18;

int n, m;
vector<vector<ll>> cost, dist, parent;
vector<vector<int>> adj;
vector<int> odd_nodes, degree, path;
vector<ll> dp;

void floyd_warshall(){
    dist = cost;
    parent.assign(n + 1, vector<ll>(n + 1, 0));

    FOR(i, 1, n){
        FOR(j, 1, n){
            if(i != j && cost[i][j] < INF) parent[i][j] = i;
        }
    }

    FOR(k, 1, n){
        FOR(i, 1, n){
            FOR(j, 1, n){
                if(dist[i][k] < INF && dist[k][j] < INF){
                    if(dist[i][k] + dist[k][j] < dist[i][j]){
                        dist[i][j] = dist[i][k] + dist[k][j];
                        parent[i][j] = parent[k][j];
                    }
                }
            }
        }
    }
}

ll min_weight_matching(int mask){
    if(mask == 0) return 0;
    if(dp[mask] != -1) return dp[mask];

    ll res = INF;
    int i = 0;

    while(!BIT(mask, i)) i++;

    for(int j = i + 1; j < (int)odd_nodes.size(); j++){
        if(BIT(mask, j)){
            int u = odd_nodes[i];
            int v = odd_nodes[j];
            int new_mask = mask ^ MASK(i) ^ MASK(j);

            res = min(res, dist[u][v] + min_weight_matching(new_mask));
        }
    }

    return dp[mask] = res;
}

void reconstruct_matching(int mask){
    if(mask == 0) return;

    int i = 0;
    while(!BIT(mask, i)) i++;

    int best_j = -1;
    ll min_val = INF;

    for(int j = i + 1; j < (int)odd_nodes.size(); j++){
        if(BIT(mask, j)){
            int u = odd_nodes[i];
            int v = odd_nodes[j];
            int new_mask = mask ^ MASK(i) ^ MASK(j);

            if(dist[u][v] + dp[new_mask] < min_val){
                min_val = dist[u][v] + dp[new_mask];
                best_j = j;
            }
        }
    }

    int u = odd_nodes[i];
    int v = odd_nodes[best_j];

    int curr = v;

    while(curr != u){
        int p = parent[u][curr];
        adj[p][curr]++;
        adj[curr][p]++;
        curr = p;
    }

    reconstruct_matching(mask ^ MASK(i) ^ MASK(best_j));
}

void hierholzer(int start){
    stack<int> st;
    st.push(start);

    while(!st.empty()){
        int u = st.top();
        int v = 1;

        while(v <= n && adj[u][v] == 0) v++;

        if(v <= n){
            adj[u][v]--;
            adj[v][u]--;
            st.push(v);
        }
        else{
            path.push_back(u);
            st.pop();
        }
    }

    reverse(ALL(path));
}

int main(){
    FAST_IO

    cin >> n >> m;

    cost.assign(n + 1, vector<ll>(n + 1, INF));
    adj.assign(n + 1, vector<int>(n + 1, 0));
    degree.assign(n + 1, 0);

    FOR(i, 1, n) cost[i][i] = 0;

    for(int i = 1; i <= m; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;

        cost[u][v] = min(cost[u][v], w);
        cost[v][u] = min(cost[v][u], w);

        adj[u][v]++;
        adj[v][u]++;

        degree[u]++;
        degree[v]++;
    }

    floyd_warshall();

    FOR(i, 1, n){
        if(degree[i] % 2) odd_nodes.push_back(i);
    }

    ll total_cost = 0;

    FOR(i, 1, n){
        for(int j = i + 1; j <= n; j++){
            if(cost[i][j] != INF && adj[i][j] > 0){
                total_cost += cost[i][j] * adj[i][j];
            }
        }
    }

    if(!odd_nodes.empty()){
        int num_odd = odd_nodes.size();
        int full_mask = (1 << num_odd) - 1;

        dp.assign(1 << num_odd, -1);

        ll extra_cost = min_weight_matching(full_mask);
        total_cost += extra_cost;

        reconstruct_matching(full_mask);
    }

    int start_node = 1;

    FOR(i, 1, n){
        if(degree[i] > 0){
            start_node = i;
            break;
        }
    }

    hierholzer(start_node);

    cout << "Tong chi phi nho nhat: " << total_cost << "\n";
    cout << "Chu trinh di qua cac canh: ";

    for(int v : path) cout << v << " ";
    cout << "\n";

    return 0;
}
