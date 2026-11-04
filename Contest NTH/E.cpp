#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);

const int MAXH = 1005;

bitset<MAXH> dp[2][2 * MAXH + 5];

int main() {
    FAST_IO

    int T;
    cin >> T;

    while (T--) {
        int n, h, w;
        cin >> n >> h >> w;

        vector<int> l(n), r(n);
        for (int i = 0; i < n; i++) {
            l[i] = 0;
            r[i] = h - 1;
        }

        vector<int> x(w), s(w), e(w);
        for (int i = 0; i < w; i++) cin >> x[i];
        for (int i = 0; i < w; i++) cin >> s[i];
        for (int i = 0; i < w; i++) cin >> e[i];

        for (int i = 0; i < w; i++) {
            l[x[i]] = s[i];
            r[x[i]] = e[i];
        }

        if (n == 1) {
            cout << "YES\n";
            continue;
        }

        int cur = 0, nxt = 1;

        for (int v = -(h - 1); v <= h - 1; v++) dp[cur][v + MAXH].reset();

        dp[cur][MAXH][h / 2] = 1;

        for (int i = 1; i < n; i++) {
            bitset<MAXH> ok;
            for (int y = l[i]; y <= r[i]; y++) ok[y] = 1;

            for (int v = -(h - 1); v <= h - 1; v++) {
                bitset<MAXH> tmp;
                if (v - 1 >= -(h - 1)) tmp |= dp[cur][v - 1 + MAXH];
                tmp |= dp[cur][v + MAXH];
                if (v + 1 <= h - 1) tmp |= dp[cur][v + 1 + MAXH];
                if (v >= 0) tmp <<= v;
                else tmp >>= -v;
                dp[nxt][v + MAXH] = tmp & ok;
            }
            swap(cur, nxt);
        }

        bool tr = false;
        for (int v = -(h - 1); v <= h - 1; v++) {
            if (dp[cur][v + MAXH].any()) {
                tr = true;
                break;
            }
        }
        cout << (tr ? "YES\n" : "NO\n");
    }

    return 0;
}