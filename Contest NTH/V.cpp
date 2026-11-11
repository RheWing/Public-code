#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXA = 10000005;
int minprime[MAXA];

void sieve(){
    for(int i = 1; i < MAXA; i++) minprime[i] = i;
    for(int i = 2; i * i < MAXA; i++){
        if(minprime[i] == i){
            for(int j = i * i; j < MAXA; j += i){
                if(minprime[j] == j){
                    minprime[j] = i;
                }
            }
        }
    }
}

vector<int> get(int x){
    vector<int> f;
    while(x > 1){
        int p = minprime[x];
        f.push_back(p);
        while(x % p == 0){
            x /= p;
        }
    }
    return f;
}

struct Q{
    int l, r, id;
    bool operator<(const Q& other) const {
        return r < other.r;
    }
};

const int MAXV = 10000005;
const int MAXN = 2e5 + 5;
int lpos[MAXV], st[4 * MAXV];
int n, q;
int a[MAXN];

void build(int node, int l, int r) {
    if (l == r) {
        if (minprime[l] == l && l >= 2) st[node] = 0;
        else st[node] = 1e9;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);
    st[node] = min(st[2 * node], st[2 * node + 1]);
}

void update(int node, int l, int r, int idx, int val) {
    if (l == r) {
        st[node] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (idx <= mid) update(2 * node, l, mid, idx, val);
    else update(2 * node + 1, mid + 1, r, idx, val);
    st[node] = min(st[2 * node], st[2 * node + 1]);
}

int query(int node, int l, int r, int limit_l) {
    if (st[node] >= limit_l) return -1;
    if (l == r) return l;
    int mid = (l + r) / 2;
    if (st[2 * node] < limit_l) {
        return query(2 * node, l, mid, limit_l);
    } else {
        return query(2 * node + 1, mid + 1, r, limit_l);
    }
}

int main(){
    FAST_IO

    sieve();

    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];

    vector<Q> que(q);
    for(int i = 0; i < q; i++){
        cin >> que[i].l >> que[i].r;
        que[i].id = i;
    }

    sort(ALL(que));

    for(int i = 0; i < MAXV; i++){
        lpos[i] = 0;
    }

    build(1, 2, MAXV - 1);

    vector<int> res(q);
    int cur = 0;
    for(int i = 0; i < q; i++){
        int l = que[i].l;
        int r = que[i].r;
        int id = que[i].id;
        
        while(cur < r){
            cur++;
            vector<int> f = get(a[cur]);
            for(int p : f){
                lpos[p] = cur;
                update(1, 2, MAXV - 1, p, cur);
            }
        }
        
        res[id] = query(1, 2, MAXV - 1, l);
    }

    for(int i = 0; i < q; i++){
        cout << res[i] << '\n';
    }

    return 0;
}