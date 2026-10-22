#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 100005;

int n;
ll x, y, a[MAXN];

bool check(ll k) {
    if (x > y) {
        ll sum = 0;
        for (int i = 1; i <= n; i++) {
            ll need = a[i] - k * y;
            if (need >= 0) {
                sum += need / (x - y) + 1;
                if (sum > k) return false;
            }
        }
        return true;
    }

    if (x == y) {
        ll mx = *max_element(a + 1, a + n + 1);
        return mx - k * x < 0;
    }

    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= k * y) return false;
        sum = min(sum + (k * y - a[i] - 1) / (y - x), k); 
    }
    return sum >= k;
}

int main() {
    FAST_IO

    cin >> n >> x >> y;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ll l = 0, r = 4000000000LL, ans = r;

    while (l <= r) {
        ll mid = (l + r) / 2;

        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans;
    return 0;
}