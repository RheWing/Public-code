#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 2e5 + 5;
const ll NEG = -1e18;
int n;
ll a[MAXN], pref[MAXN], st[4 * MAXN], c[MAXN], dp[MAXN];
int L[MAXN], R[MAXN];

void update(int id, int l, int r, int pos, ll val){
    if(l == r){
        st[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    if(pos <= mid) update(id * 2, l, mid, pos, val);
    else update(id * 2 + 1, mid + 1, r, pos, val);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

ll query(int id, int l, int r, int u, int v){
    if(v < l || r < u) return NEG;
    if(u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    return max(query(id * 2, l, mid, u, v), query(id * 2 + 1, mid + 1, r, u, v));
}

int main(){
    FAST_IO

    cin >> n;
    pref[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }

    for(int i = 1; i <= n; i++){
        cin >> L[i] >> R[i] >> c[i];
    }

    fill(st, st + 4 * (n + 1), NEG);
    dp[0] = 0;
    update(1, 0, n, 0, dp[0] - pref[0]);
    for(int i = 1; i <= n; i++){
        dp[i] = dp[i - 1];
        int ql = max(0, i - R[i]);
        int qr = i - L[i];
        if(ql <= qr){
            ll mxv = query(1, 0, n, ql, qr);
            if(mxv != NEG){
                ll op2 = mxv + pref[i] - c[i];
                dp[i] = max(dp[i], op2);
            }
        }
        update(1, 0, n, i, dp[i] - pref[i]);
    }

    cout << dp[n] << '\n';

    return 0;
}