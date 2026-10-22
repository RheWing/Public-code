
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);

const int MAXN = 200005;

int n, q;
ll s, t, a[MAXN], P[MAXN];

ll lev(ll v){
    if(v >= s) return 1;
    return 1 + (s - v + t - 1) / t;
}

int main(){
    FAST_IO

    cin >> n >> s >> t;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    for(int i = 1; i <= n; i++){
        ll L = lev(a[n - i + 1]);
        P[i] = max(P[i - 1] + 1, L);
    }

    cin >> q;

    string res = "";

    while(q--){
        ll v;
        int i;
        cin >> v >> i;

        int j = lower_bound(a + 1, a + n + 1, v) - a;
        int m = n - j + 1;

        ll k = lev(v);

        int cnt = lower_bound(P + 1, P + n + 1, k) - (P + 1);
        ll lo = cnt + 1;

        ll p = max(k, P[m] + 1);
        ll thr = s - (p - 1) * t;

        ll hi = n - (lower_bound(a + 1, a + n + 1, thr) - (a + 1));

        res += (lo <= i && i <= hi) ? '1' : '0';
    }

    cout << res << '\n';

    return 0;
}
