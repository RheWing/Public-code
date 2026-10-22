#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);

const int MAXN = 509;
const int MOD = 1e9 + 7;

int n, k;
int a[MAXN], b[MAXN];
int preA[MAXN], preB[MAXN];
int dp[MAXN][MAXN];
int pre[MAXN][MAXN];

vector<int> posA[MAXN], posB[MAXN];

void Add(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

bool cmpA(int i, int j) {
    return 1LL * (preA[k] - preA[i]) * (k - j)
         < 1LL * (preA[k] - preA[j]) * (k - i);
}

bool cmpB(int i, int j) {
    return 1LL * (preB[k] - preB[i]) * (k - j)
         < 1LL * (preB[k] - preB[j]) * (k - i);
}

int main() {
    FAST_IO

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        preA[i] = preA[i - 1] + a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        preB[i] = preB[i - 1] + b[i];
    }

    for (int j = 1; j <= n; j++) {
        k = j;

        for (int i = 0; i < j; i++) {
            posA[j].push_back(i);
        }

        posB[j] = posA[j];

        sort(ALL(posA[j]), cmpA);
        sort(ALL(posB[j]), cmpB);
    }

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int p = 0; p < (int)posA[i].size(); p++) {
                pre[j][p] = (p > 0 ? pre[j][p - 1] : 0);
                Add(pre[j][p], dp[posA[i][p]][j]);
            }

            int idx = -1;

            for (int q : posB[j]) {
                while (idx + 1 < (int)posA[i].size()
                    && 1LL * (preA[i] - preA[posA[i][idx + 1]]) * (j - q)
                    <= 1LL * (preB[j] - preB[q]) * (i - posA[i][idx + 1])) {
                    idx++;
                }

                if (idx >= 0) {
                    Add(dp[i][j], pre[q][idx]);
                }
            }
        }
    }

    cout << dp[n][n];

    return 0;
}