#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 1e5 + 5;
int n, q;
int par[MAXN], sz[MAXN];
vector<array<int,3>> e;
vector<int> wss;
vector<ll> cnt;

int find(int u){
    if(par[u] == u) return u;
    return par[u] = find(par[u]);
}

bool uni(int u, int v){
    u = find(u);
    v = find(v);
    if(u != v){
        if(sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        return true;
    }
    return false;

}

int get(int u){
    return sz[find(u)];
}

ll F(int x){
    int idx = upper_bound(ALL(wss), x) - wss.begin();
    if(idx == 0) return 0;
    return cnt[idx - 1];
}

int main(){
    FAST_IO

    cin >> n >> q;
    for(int i = 1; i < n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        e.push_back({w, u, v});
    }
    sort(ALL(e));

    for(int i = 1; i <= n; i++){
        par[i] = i;
        sz[i] = 1;
    }

    ll cur = 0;
    for(auto &ed : e){
        int w = ed[0], u = ed[1], v = ed[2];
        if(find(u) != find(v)){

            cur += (ll)get(u) * get(v);
            uni(u, v);
            wss.push_back(w);
            cnt.push_back(cur);
        }
    }

    while(q--){
        int l, r;
        cin >> l >> r;
        cout << F(r) - F(l - 1) << " ";
    }
    cout << "\n";

    return 0;
}