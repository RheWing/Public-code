#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);

const int N = 50005;

int n, m;
int col[N];
vector<int> g[N];
int par[N], dep[N], sz[N], heavy[N], head[N], pos[N], nat[N];
vector<int> cp[N];      

struct P{ 
    int c, k; 
};    

P comb(P a, P b){
    if(a.k == 0) return b;
    if(b.k == 0) return a;
    if(a.c == b.c) return {a.c, a.k + b.k};
    if(a.k >= b.k) return {a.c, a.k - b.k};
    return {b.c, b.k - a.k};
}

P seg[4 * N];
int bar[N];            

void build(int id, int l, int r){
    if(l == r){ 
        seg[id] = {bar[l], 1}; 
        return; 
    }
    int mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    seg[id] = comb(seg[2 * id], seg[2 * id + 1]);
}

P query(int id, int l, int r, int ql, int qr){
    if(qr < l || r < ql) return {0, 0};
    if(ql <= l && r <= qr) return seg[id];
    int mid = (l + r) / 2;
    return comb(query(2 * id, l, mid, ql, qr), query(2 * id + 1, mid + 1, r, ql, qr));
}

int cntr(int c, int l, int r){
    const vector<int>& v = cp[c];
    return upper_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l);
}

vector<pair<int, int>> pathr(int u, int v){
    vector<pair<int, int>> res;
    while(head[u] != head[v]){
        if(dep[head[u]] < dep[head[v]]) swap(u, v);
        res.push_back({pos[head[u]], pos[u]});
        u = par[head[u]];
    }
    if(dep[u] > dep[v]) swap(u, v);
    res.push_back({pos[u], pos[v]});
    return res;
}

int solve(int t, int u, int v){
    vector<pair<int, int>> ras;
    ll S = 0;

    if(t == 1){
        ras.push_back({pos[u], pos[u] + sz[u] - 1});
        S = sz[u];
    } else if(t == 2){
        if(pos[u] > 0) ras.push_back({0, pos[u] - 1});
        if(pos[u] + sz[u] <= n - 1) ras.push_back({pos[u] + sz[u], n - 1});
        S = n - sz[u];
    } else{
        ras = pathr(u, v);
        for(auto [l, r] : ras) S += r - l + 1;
    }

    if(S == 0) return -1;

    P res = {0, 0};
    for(auto [l, r] : ras) res = comb(res, query(1, 0, n - 1, l, r));
    if(res.k == 0) return -1;

    int c = res.c;
    ll cnt = 0;
    for(auto [l, r] : ras) cnt += cntr(c, l, r);

    return (2 * cnt > S) ? c : -1;
}

int main(){
    FAST_IO

    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> col[i];
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> order;
    order.reserve(n);
    order.push_back(1);
    par[1] = 0;
    dep[1] = 0;
    for(int i = 0; i < (int)order.size(); i++){
        int x = order[i];
        for(int y : g[x]){
            if(y == par[x]) continue;
            par[y] = x;
            dep[y] = dep[x] + 1;
            order.push_back(y);
        }
    }

    for(int i = 1; i <= n; i++){ 
        sz[i] = 1; 
        heavy[i] = 0; 
    }
    for(int i = n - 1; i >= 1; i--){
        int x = order[i];
        sz[par[x]] += sz[x];
    }
    for(int i = 1; i <= n; i++){
        int best = 0;
        for(int y : g[i]){
            if(y == par[i]) continue;
            if(best == 0 || sz[y] > sz[best]) best = y;
        }
        heavy[i] = best;
    }

    vector<int> st;
    st.push_back(1);
    head[1] = 1;
    int timer = 0;
    while(!st.empty()){
        int x = st.back();
        st.pop_back();
        pos[x] = timer;
        nat[timer] = x;
        timer++;
        for(int y : g[x]){
            if(y == par[x] || y == heavy[x]) continue;
            head[y] = y;
            st.push_back(y);
        }
        if(heavy[x]){
            head[heavy[x]] = head[x];
            st.push_back(heavy[x]);
        }
    }

    for(int p = 0; p < n; p++) bar[p] = col[nat[p]];
    build(1, 0, n - 1);

    for(int x = 1; x <= n; x++) cp[col[x]].push_back(pos[x]);
    for(int c = 1; c <= n; c++) sort(cp[c].begin(), cp[c].end());

    while(m--){
        int t;
        cin >> t;
        int u = 0, v = 0;
        if(t == 3) cin >> u >> v;
        else cin >> u;
        cout << solve(t, u, v) << '\n';
    }

    return 0;
}
