#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);

const int MAXN = 100005;

int n, m;
vector<int> adj[MAXN], revAdj[MAXN];
bool vis[MAXN];

void dfs(int u, vector<int> g[]){
    vis[u] = true;
    for(int v : g[u]){
        if(!vis[v]){
            dfs(v, g);
        }
    }
}

int main(){
    FAST_IO;

    cin >> n >> m;

    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        revAdj[v].push_back(u);
    }

    dfs(1, adj);

    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            cout << "NO\n";
            cout << 1 << ' ' << i << '\n';
            return 0;
        }
    }

    memset(vis, 0, sizeof(vis));

    dfs(1, revAdj);

    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            cout << "NO\n";
            cout << i << ' ' << 1 << '\n';
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}