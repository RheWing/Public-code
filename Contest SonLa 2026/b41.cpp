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
struct Data{
    int u, v;
    ll w;
    bool operator<(const Data& other) const{
        return w < other.w;
    }
};

struct DSU{
    vector<int> par;
    vector<ll> sz;
    DSU(int n){
        par.resize(n + 1);
        sz.resize(n + 1, 1);
        for(int i = 1; i <= n; i++) par[i] = i;
    }

    int find(int v){
        if(v == par[v]) return v;
        return par[v] = find(par[v]);
    }

    ll uni(int a, int b){
        a = find(a);
        b = find(b);
        if(a != b){
            ll p = sz[a] * sz[b];
            if(sz[a] < sz[b]) swap(a, b);
            par[b] = a;
            sz[a] += sz[b];
            return p;
        }
        return 0;
    }
};

int n, q;
int a[MAXN];

int main(){
    FAST_IO

    cin >> n >> q;

    vector<Data> e(n - 1);
    for(int i = 0; i < n - 1; i++){
        cin >> e[i].u >> e[i].v >> e[i].w;
    }

    sort(ALL(e));

    DSU dsu(n);
    vector<ll> we(n - 1);
    vector<ll> pref(n - 1, 0);
    
    for(int i = 0; i < n - 1; i++){
        we[i] = e[i].w;
        ll p = dsu.uni(e[i].u, e[i].v);
        ll cost = e[i].w * p;
        pref[i] = cost;
        if(i > 0) pref[i] += pref[i - 1];
    }

    while(q--){
        ll l, r; cin >> l >> r;
        int idxl = lower_bound(ALL(we), l) - we.begin();
        int idxr = upper_bound(ALL(we), r) - we.begin() - 1;
        
        if(idxl <= idxr){
            ll res = pref[idxr];
            if(idxl > 0) res -= pref[idxl - 1];
            cout << res << '\n';
        }
        else{
            cout << 0 << '\n';
        }
    }
    return 0;
}