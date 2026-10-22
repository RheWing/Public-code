#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const ll INF = (ll)1e18;

int m;
vector<ll> c, mn, lz, totA, totB, pa, sb, best;

void app(int x, ll k){
    mn[x] += k;
    lz[x] += k;
    pa[x] = totA[x];
    sb[x] = totB[x];
    best[x] = totA[x] - totB[x]; 
}

void push(int x){
    if(lz[x]){
        app(2 * x, lz[x]);
        app(2 * x + 1, lz[x]);
        lz[x] = 0;
    }
}

void pull(int x){
    int L = 2 * x, R = 2 * x + 1;
    mn[x] = min(mn[L], mn[R]);
    totA[x] = max(totA[L], totA[R]);
    totB[x] = min(totB[L], totB[R]);
    pa[x] = (mn[L] == 0) ? pa[L] : max(totA[L], pa[R]);
    sb[x] = (mn[R] == 0) ? sb[R] : min(totB[R], sb[L]);
    best[x] = max({best[L], best[R], pa[R] - sb[L]});
}

void build(int x, int l, int r){
    mn[x] = 0;
    lz[x] = 0;
    totA[x] = pa[x] = -INF;
    totB[x] = sb[x] = INF;
    best[x] = -2 * INF;

    if(l == r) return;

    int mid = (l + r) / 2;
    build(2 * x, l, mid);
    build(2 * x + 1, mid + 1, r);
}

void upd(int x, int l, int r, int pos, bool isA){
    if(l == r){
        if(isA) totA[x] = c[l];
        else totB[x] = c[l];

        if(mn[x] == 0){
            pa[x] = -INF;
            sb[x] = totB[x];
        }
        else{
            pa[x] = totA[x];
            sb[x] = totB[x];
        }

        best[x] = totA[x] - totB[x];
        return;
    }

    push(x);

    int mid = (l + r) / 2;
    if(pos <= mid) upd(2 * x, l, mid, pos, isA);
    else upd(2 * x + 1, mid + 1, r, pos, isA);

    pull(x);
}

void add(int x, int l, int r, int ql, int qr){
    if(qr < l || r < ql) return;

    if(ql <= l && r <= qr){
        app(x, 1);
        return;
    }

    push(x);

    int mid = (l + r) / 2;
    add(2 * x, l, mid, ql, qr);
    add(2 * x + 1, mid + 1, r, ql, qr);

    pull(x);
}

int main(){
    FAST_IO

    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;

        vector<ll> a(n), b(n);

        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        vector<ll> val;

        for(int i = 0; i < n; i++){
            val.push_back(a[i]);
            val.push_back(b[i]);
        }

        sort(ALL(val));
        val.erase(unique(ALL(val)), val.end());

        m = val.size();
        c.assign(m + 1, 0);

        for(int i = 0; i < m; i++) c[i + 1] = val[i];

        int sz = 4 * m + 4;

        mn.assign(sz, 0);
        lz.assign(sz, 0);
        totA.assign(sz, 0);
        totB.assign(sz, 0);
        pa.assign(sz, 0);
        sb.assign(sz, 0);
        best.assign(sz, 0);

        build(1, 1, m);

        ll SA = 0, SB = 0;

        for(int i = 0; i < n; i++){
            int ia = lower_bound(ALL(val), a[i]) - val.begin() + 1;
            int ib = lower_bound(ALL(val), b[i]) - val.begin() + 1;

            SA += a[i];
            SB += b[i];

            if(ib + 1 <= ia) add(1, 1, m, ib + 1, ia);

            upd(1, 1, m, ia, true);
            upd(1, 1, m, ib, false);

            ll gain = max(0LL, best[1]);
            cout << SA - SB - gain << ' ';
        }

        cout << '\n';
    }

    return 0;
}