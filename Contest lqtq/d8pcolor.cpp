
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 10005;

int n, m;
vector<int> adj[MAXN];
int deg[MAXN], color[MAXN], vis[MAXN];
int mark[MAXN], timer = 0;
queue<int> q;
vector<int> order;

bool check(int s, int t, int c1, int c2){
    queue<int> qu;
    timer++;
    qu.push(s);
    mark[s] = timer;

    while(!qu.empty()){
        int u = qu.front();
        qu.pop();
        if(u == t) return false;
        for(int v : adj[u]){
            if(mark[v] != timer && (color[v] == c1 || color[v] == c2)){
                mark[v] = timer;
                qu.push(v);
            }
        }
    }
    return true;
}

void changeColor(int s, int c1, int c2){
    queue<int> qu;
    timer++;
    qu.push(s);
    mark[s] = timer;

    while(!qu.empty()){
        int u = qu.front();
        qu.pop();
        if(color[u] == c1) color[u] = c2;
        else color[u] = c1;
        for(int v : adj[u]){
            if(mark[v] != timer && (color[v] == c1 || color[v] == c2)){
                mark[v] = timer;
                qu.push(v);
            }
        }
    }
}

int main(){
    FAST_IO

    cin >> n >> m;

    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    for(int i = 1; i <= n; i++) if(deg[i] <= 5) q.push(i);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        order.push_back(u);
        for(int v : adj[u]){
            if(!vis[v]){
                deg[v]--;
                if(deg[v] == 5) q.push(v);
            }
        }
    }

    if((int)order.size() != n) return 0;
    for(int i = n - 1; i >= 0; i--){
        int u = order[i];
        bool used[6] = {};

        for(int v : adj[u]) if(color[v]) used[color[v]] = 1;

        int c = 0;
        for(int j = 1; j <= 5; j++){
            if(!used[j]){
                c = j;
                break;
            }
        }

        if(c){
            color[u] = c;
            continue;
        }

        bool found = false;

        for(int j = 0; j < (int)adj[u].size() && !found; j++){
            for(int k = j + 1; k < (int)adj[u].size() && !found; k++){
                int v1 = adj[u][j];
                int v2 = adj[u][k];
                if(!color[v1] || !color[v2]) continue;
                if(color[v1] == color[v2]) continue;

                int c1 = color[v1];
                int c2 = color[v2];
                if(check(v1, v2, c1, c2)){
                    changeColor(v1, c1, c2);
                    color[u] = c1;
                    found = true;
                }
            }
        }
        if(!found) return 0;
    }

    int mx = 0;

    for(int i = 1; i <= n; i++) mx = max(mx, color[i]);
    cout << mx << '\n';
    for(int i = 1; i <= n; i++) cout << color[i] << ' ';

    return 0;
}
