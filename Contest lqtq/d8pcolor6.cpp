
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 300005;

int n, m;
vector<int> adj[MAXN];
int deg[MAXN], color[MAXN], vis[MAXN];
queue<int> q;
vector<int> order;

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

    for(int i = n - 1; i >= 0; i--){
        int u = order[i];
        bool used[7] = {};

        for(int v : adj[u]) if(color[v]) used[color[v]] = 1;

        for(int j = 1; j <= 6; j++){
            if(!used[j]){
                color[u] = j;
                break;
            }
        }
    }

    int mx = 0;
    for(int i = 1; i <= n; i++){
        mx = max(mx, color[i]);
    }

    cout << mx << '\n';
    for(int i = 1; i <= n; i++){
        cout << color[i] << ' ';
    }

    return 0;
}
