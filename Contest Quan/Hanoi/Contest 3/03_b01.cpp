
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);

const int MAXN = 200005;
int n, q, timer = 0;
int par[MAXN], dep[MAXN], sz[MAXN];
int heavy[MAXN], head[MAXN], pos[MAXN];
ll w[MAXN], st[4 * MAXN];
vector<int> adj[MAXN];

void dfs(int u, int p){
    par[u] = p;
    sz[u] = 1;
    heavy[u] = 0;
    int mx = 0;

    for(int v : adj[u]){
        if(v == p) continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
        sz[u] += sz[v];

        if(sz[v] > mx){
            mx = sz[v];
            heavy[u] = v;
        }
    }
}

void hld(int u, int h){
    head[u] = h;
    pos[u] = ++timer;

    if(heavy[u]) hld(heavy[u], h);

    for(int v : adj[u]){
        if(v == par[u] || v == heavy[u]) continue;
        hld(v, v);
    }
}

void build(int id, int l, int r){
    if(l == r){
        st[id] = w[l];
        return;
    }

    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = st[id * 2] ^ st[id * 2 + 1];
}

void update(int id, int l, int r, int p, ll val){
    if(l == r){
        st[id] = val;
        return;
    }

    int mid = (l + r) / 2;
    if(p <= mid) update(id * 2, l, mid, p, val);
    else update(id * 2 + 1, mid + 1, r, p, val);

    st[id] = st[id * 2] ^ st[id * 2 + 1];
}

ll get(int id, int l, int r, int u, int v){
    if(v < l || r < u) return 0;
    if(u <= l && r <= v) return st[id];

    int mid = (l + r) / 2;
    return get(id * 2, l, mid, u, v) ^ get(id * 2 + 1, mid + 1, r, u, v);
}

ll query(int u, int v){
    ll ans = 0;

    while(head[u] != head[v]){
        if(dep[head[u]] < dep[head[v]]) swap(u, v);

        ans ^= get(1, 1, n, pos[head[u]], pos[u]);
        u = par[head[u]];
    }

    if(dep[u] > dep[v]) swap(u, v);

    ans ^= get(1, 1, n, pos[u], pos[v]);

    return ans;
}

int main(){
    FAST_IO

    cin >> n >> q;

    for(int i = 1; i <= n; i++) cin >> w[i];

    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    hld(1, 1);

    ll b[MAXN] = {};
    for(int i = 1; i <= n; i++) b[pos[i]] = w[i];
    for(int i = 1; i <= n; i++) w[i] = b[i];

    build(1, 1, n);

    while(q--){
        int type, u;
        ll v;
        cin >> type >> u >> v;

        if(type == 1){
            update(1, 1, n, pos[u], v);
        }
        else{
            cout << query(u, v) << '\n';
        }
    }

    return 0;
}
