#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).r()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task "GAMES"
#define MAXN 100005
#define INF 1e9 + 7

int n, m;
ll h[MAXN];
ll tree[4 * MAXN];
ll lazy[4 * MAXN];

void build(int node, int l, int r){
    if(l == r){
        tree[node] = h[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

void pushdown(int node){
    if(lazy[node] != 0){
        lazy[2 * node] = lazy[node];
        tree[2 * node] = lazy[node];
        
        lazy[2 * node + 1] = lazy[node];
        tree[2 * node + 1] = lazy[node];
        
        lazy[node] = 0;
    }
}

void update(int node, int l, int r, int u, int v, ll val){
    if (v < l || r < u){
        return;
    }
    if(u <= l && r <= v){
        tree[node] = val;
        lazy[node] = val;
        return;
    }
    
    pushdown(node);
    
    int mid = (l + r) / 2;
    update(2 * node, l, mid, u, v, val);
    update(2 * node + 1, mid + 1, r, u, v, val);
    
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

ll query(int node, int l, int r, int u, int v){
    if (v < l || r < u) {
        return 0;
    }
    if (u <= l && r <= v) {
        return tree[node];
    }
    
    pushdown(node);
    
    int mid = (l + r) / 2;
    ll l_max = query(2 * node, l, mid, u, v);
    ll r_max = query(2 * node + 1, mid + 1, r, u, v);
    
    return max(l_max, r_max);
}

int main() {
    FAST_IO
    FILE_IO

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }

    build(1, 1, n);

    for (int i = 1; i <= m; ++i) {
        int p, x;
        cin >> p >> x;
        
        int l = p;
        int r = p + x - 1;

        ll max_h = query(1, 1, n, l, r);

        ll new_h = max_h + 1;
        cout << new_h << "\n";

        update(1, 1, n, l, r, new_h);
    }

    return 0;
}
