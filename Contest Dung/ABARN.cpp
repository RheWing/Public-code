#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".inp","r",stdin); freopen(task".out","w",stdout);
#define task ""
#define MAXN 100005

struct Data{
    int lazy;
    int val;
} st[4 * MAXN];
int a[MAXN];
vector<pii> ba;

void build(int id, int l, int r){
    st[id].lazy = 0;
    if(l == r){
        st[id].val = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    st[id].val = min(st[id * 2].val, st[id * 2 + 1].val);
}

void down(int id){
    int t = st[id].lazy;
    st[id * 2].lazy += t;
    st[id * 2].val += t;
    st[id * 2 + 1].lazy += t;
    st[id * 2 + 1].val += t;
    st[id].lazy = 0;
}

void update(int id, int l, int r, int u, int v){
    if(v < l || r < u){
        return;
    }
    if(u <= l && r <= v){
        st[id].val -= 1;
        st[id].lazy -= 1;
        return;
    }
    int m = (l + r) / 2;
    down(id);
    update(id * 2, l, m, u, v);
    update(id * 2 + 1, m + 1, r, u, v);
    st[id].val = min(st[id * 2].val, st[id * 2 + 1].val);
}

int query(int id, int l, int r, int u, int v){
    if(v < l || r < u) return 1e9;
    if(u <= l && r <= v){
        return st[id].val;
    }
    int m = (l + r)/ 2;
    down(id);

    return min(query(id * 2, l, m, u, v), query(id * 2 + 1, m + 1, r, u, v));
}

int n, m;

int main() {
    FAST_IO
    
    cin >> n >> m; 
    
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int i = 1; i <= m; i++){
        int b, a; cin >> a >> b;
        ba.push_back({b, a});
    }

    sort(ALL(ba));


    build(1, 1, n);

    int res = 0;

    for(int i = 0; i < m; i++){
        int r = ba[i].first;
        int l = ba[i].second;

        if(query(1, 1, n, l, r) > 0){
            res++;
            update(1, 1, n, l, r);
        }
    }

    cout << res << '\n';

    return 0;
}
