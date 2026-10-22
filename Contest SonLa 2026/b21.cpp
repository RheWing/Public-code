
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = (1 << 20) + 5;

int n, N, q;
int a[MAXN];
ll st[4 * MAXN], lazy[4 * MAXN];
bool has[4 * MAXN];

void app(int id, int l, int r, ll v){
    st[id] = 1LL * (r - l + 1) * v;
    lazy[id] = v;
    has[id] = 1;
}

void push(int id, int l, int r){
    if(!has[id] || l == r) return;

    int mid = (l + r) / 2;

    app(id * 2, l, mid, lazy[id]);
    app(id * 2 + 1, mid + 1, r, lazy[id]);

    has[id] = 0;
}

void build(int id, int l, int r){
    if(l == r){
        st[id] = a[l];
        return;
    }

    int mid = (l + r) / 2;

    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);

    st[id] = st[id * 2] + st[id * 2 + 1];
}

void update(int id, int l, int r, int u, int v, int k, int x, int bit){
    if(u <= l && r <= v){
        app(id, l, r, x);
        return;
    }

    push(id, l, r);

    int mid = (l + r) / 2;
    int lNode = id * 2;
    int rNode = id * 2 + 1;

    if(bit >= 0 && BIT(k, bit)) swap(lNode, rNode);

    if(u <= mid) update(lNode, l, mid, u, v, k, x, bit - 1);

    if(v > mid) update(rNode, mid + 1, r, u, v, k, x, bit - 1);

    st[id] = st[id * 2] + st[id * 2 + 1];
}

ll query(int id, int l, int r, int u, int v, int k, int bit){
    if(u <= l && r <= v) return st[id];

    push(id, l, r);

    int mid = (l + r) / 2;
    int lNode = id * 2;
    int rNode = id * 2 + 1;

    if(bit >= 0 && BIT(k, bit)) swap(lNode, rNode);

    ll res = 0;

    if(u <= mid) res += query(lNode, l, mid, u, v, k, bit - 1);

    if(v > mid) res += query(rNode, mid + 1, r, u, v, k, bit - 1);

    return res;
}

int main(){
    FAST_IO

    cin >> n;
    N = 1 << n;

    for(int i = 0; i < N; i++) cin >> a[i];

    build(1, 0, N - 1);

    cin >> q;

    while(q--){
        int t, l, r, k;
        cin >> t >> l >> r >> k;

        if(t == 1){
            int v;
            cin >> v;
            update(1, 0, N - 1, l, r, k, v, n - 1);
        }
        else{
            cout << query(1, 0, N - 1, l, r, k, n - 1) << '\n';
        }
    }

    return 0;
}
