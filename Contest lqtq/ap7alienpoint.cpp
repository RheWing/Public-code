#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);

const int MAXN = 2e5 + 5;

struct Data {
    ll c;
    int cnt;

    bool operator<(const Data& other) const {
        if (c != other.c) return c < other.c;
        return cnt < other.cnt;
    }
};

int n, k;
ll h[MAXN];
Data dp[MAXN];

Data solve(ll delta) {
    dp[0] = dp[1] = {0, 0};
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1];
        ll d = h[i] - h[i - 1];
        ll cost = dp[i - 2].c + d - delta;
        Data p = {cost, dp[i - 2].cnt - 1};
        if (p < dp[i]) dp[i] = p;
    }
    return dp[n];
}

int main() {
    FAST_IO

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    sort(h + 1, h + n + 1);

    ll l = 0, r = (h[n] - h[1]);
    ll ans = 0;
    while (l <= r) {
        ll m = l + (r - l) / 2;
        Data val = solve(m);
        if (-val.cnt >= k){ 
            r = m - 1;
            ans = val.c + k * m;
        }
        else l = m + 1;
    }

    cout << ans;

    return 0;
}
