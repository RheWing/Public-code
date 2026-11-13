#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);

const int MAXN = 200005;
int n;
int a[MAXN];
vector<int> adj[MAXN];
set<int>* s[MAXN];
int res[MAXN];

void dfs(int u, int p){
    s[u] = new set<int>();
    s[u]->insert(a[u]);

    int max_sz = -1;
    int heavy_child = -1;

    for(int v : adj[u]){
        if(v == p) continue;
        dfs(v, u);
        if((int)s[v]->size() > max_sz){
            max_sz = s[v]->size();
            heavy_child = v;
        }
    }

    if(heavy_child != -1){
        s[u] = s[heavy_child];
        s[u]->insert(a[u]);
    }

    for(int v : adj[u]){
        if(v == p || v == heavy_child) continue;
        for(int color : *s[v]){
            s[u]->insert(color);
        }
        delete s[v];
    }
    res[u] = s[u]->size();
}

int main() {
    FAST_IO

    cin >> n;

    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    dfs(1, 0);

    for(int i = 1; i <= n; i++){
        cout << res[i] << (i == n ? "" : " ");
    }
    cout << "\n";

    return 0;
}