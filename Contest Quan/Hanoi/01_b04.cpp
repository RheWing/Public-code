#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 25;

int n;
int req[MAXN];
ll dp[1 << 20];

int main() {
    FAST_IO

    cin >> n;

    for (int i = 1; i <= n; i++) {
        int mask_req = 0;
        for (int j = 1; j <= n; j++) {
            if ((i & j) == j && i != j) {
                mask_req |= (1 << (j - 1));
            }
        }
        req[i - 1] = mask_req;
    }

    dp[0] = 1; 
    int num = 1 << n;
    for (int mask = 0; mask < num; mask++) {
        if (dp[mask] == 0) continue;
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) {
                if ((mask & req[i]) == req[i]) {
                    dp[mask | (1 << i)] += dp[mask];
                }
            }
        }
    }

    cout << dp[num - 1] << "\n";

    return 0;
}
