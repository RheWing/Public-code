#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 100005;

int n, m;
vector<int> adj[MAXN];
int cat[MAXN];
int res = 0;

void DFS(int u, int p, int k){
    if(k > m) return;
    int ok = 1;
    for(int v : adj[u]){
        if(v != p){
            ok = 0;
            DFS(v, u, k * cat[v] + cat[v]);
        }
    }
    res += ok;
}

int main(){
    FAST_IO

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        cin >> cat[i];
    }

    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(1, 1, cat[1]);

    cout << res;

    return 0;
}