#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);

const int MAXN = 100005;

int n, q;
ll a[MAXN], x;
ll mx_r[MAXN], mn_r[MAXN];
int g[MAXN];

ll cnt(int l, int r){
    int m = (l + r) / 2;
    int lr = r - m;

    ll cmx = LLONG_MIN, cmn = LLONG_MAX;
    for(int k = 0; k < lr; k++){
        cmx = max(cmx, a[m + 1 + k]);
        cmn = min(cmn, a[m + 1 + k]);
        mx_r[k] = cmx;
        mn_r[k] = cmn;
        g[k + 1] = g[k] + (cmx * cmn <= x);
    }
    g[0] = 0;

    ll res = 0;
    int p2 = 0, p3 = 0, t = 0, s = 0;
    ll l_mx = LLONG_MIN, l_mn = LLONG_MAX;

    for(int i = m; i >= l; i--){
        l_mx = max(l_mx, a[i]);
        l_mn = min(l_mn, a[i]);

        while(p2 < lr && mn_r[p2] >= l_mn) p2++;
        while(p3 < lr && mx_r[p3] <= l_mx) p3++;

        int p1 = min(p2, p3);
        if(l_mx * l_mn <= x) res += p1;

        ll lim1 = x / l_mn;
        while(t < lr && mx_r[t] <= lim1) t++;
        res += max(0, min(p2, t) - p3);

        ll lim2 = x / l_mx;
        while(s < lr && mn_r[s] > lim2) s++;
        res += max(0, p3 - max(p2, s));

        int c = max(p2, p3);
        res += g[lr] - g[c];
    }
    return res;
}

ll solve(int l, int r){
    if(l == r) return (a[l] * a[l] <= x) ? 1 : 0;
    int m = (l + r) / 2;
    return solve(l, m) + solve(m + 1, r) + cnt(l, r);
}

int main(){
    FAST_IO
    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> a[i];
    while(q--){
        cin >> x;
        cout << solve(0, n - 1) << '\n';
    }
    return 0;
}