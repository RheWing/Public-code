
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);

const int MOD = 1000000007;
const int MAXN = 100005;
const int S = 1 << 19;

int n, a[MAXN], cnt[71], mask[71];
int p[19] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};

ll dp[S], ndp[S];

int main() {
    FAST_IO

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    for (int x = 1; x <= 70; x++) {
        int t = x;
        for (int j = 0; j < 19; j++) {
            int c = 0;
            while (t % p[j] == 0) {
                t /= p[j];
                c++;
            }
            if (c % 2) mask[x] |= (1 << j);
        }
    }

    dp[0] = 1;
    for (int x = 1; x <= 70; x++) {
        if (!cnt[x]) continue;
        ll w = 1;
        for (int i = 1; i < cnt[x]; i++) w = w * 2 % MOD;
        for (int m = 0; m < S; m++) ndp[m] = w * (dp[m] + dp[m ^ mask[x]]) % MOD;
        for (int m = 0; m < S; m++) dp[m] = ndp[m];
    }

    cout << (dp[0] - 1 + MOD) % MOD;

    return 0;
}
