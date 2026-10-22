#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);

const ll INF = LLONG_MAX;

int main(){
    FAST_IO

    int n;
    cin >> n;

    vector<ll> a(n + 1), b(n + 1), c(n + 1);

    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    for(int i = 1; i <= n; i++) cin >> c[i];

    ll x0, y0;
    cin >> x0 >> y0;

    ll A = 0;
    for(int i = 1; i <= n; i++) A += a[i];

    ll X0 = x0 + A;
    ll Y0 = y0 + A;

    vector<pair<ll, ll>> p(n);
    ll suf = 0;

    for(int i = n; i >= 1; i--){
        p[i - 1] = {b[i] + suf, c[i] + suf};
        suf += a[i];
    }

    sort(ALL(p));

    ll best = 0, pm = INF;

    for(int i = 0; i < n; i++){
        ll v = min(X0, p[i].first);
        best = max(best, v + min(Y0, pm));
        pm = min(pm, p[i].second);
    }

    best = max(best, X0 + min(Y0, pm));

    cout << best << '\n';

    return 0;
}