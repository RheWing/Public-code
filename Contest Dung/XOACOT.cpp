#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask,i) (((mask)>>(i))&1)
#define MASK(i) (1LL<<(i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""
const int MAXN = 100005;
const ll INF = 1e18;

struct DSU{
    int par[MAXN];
    int sz[MAXN];

    DSU(int n){
        for(int i = 1; i <= n; i++){
            par[i] = i;
            sz[i] = 1;
        }
    }

    int find(int u){
        if(par[u] == u) return u;
        return par[u] = find(par[u]);
    }

    bool unite(int u, int v){
        u = find(u);
        v = find(v);

        if(u == v) return 0;

        if(sz[u]< sz[v]) swap(u, v);

        par[v] = u;
        sz[u] += sz[v];
        return 1;
    }
};

int a[MAXN], b[MAXN], c[MAXN];
int cntb[MAXN], cntc[MAXN];
int ed[MAXN], n;
bool ok[MAXN];

int main(){
    FAST_IO

    cin >> n;

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> c[i];

    DSU dsu(n);

    for(int i = 1; i <= n; i++){
        ed[i] = 0;
        cntb[i] = 0;
        cntc[i] = 0;
        ok[i] = 1;
    }
    
    for(int i = 0 ; i < n; i++){
        dsu.unite(a[i], b[i]);
        dsu.unite(a[i], c[i]);
    }

    for(int i = 0; i < n; i++){
        int root = dsu.find(a[i]);
        ed[root]++;
        cntb[b[i]]++;
        cntc[c[i]]++;
    }

    for(int v = 1; v <= n; v++){
        if(cntb[v] != 1 || cntc[v] != 1){
            ok[dsu.find(v)] = 0;
        }
    }

    int k = 0;

    for(int v = 1; v <= n; v++){
        if(dsu.par[v] != v) continue;
        if(ok[v] && ed[v] == dsu.sz[v]){
            k += ed[v];
        }
    }

    cout << n - k << '\n';

    return 0;
}