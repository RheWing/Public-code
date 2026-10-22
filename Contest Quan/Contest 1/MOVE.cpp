#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);

const int MAXN = 505;
int n, m;
int a[MAXN][MAXN];
ll dp[MAXN][MAXN];

int main(){
    FAST_IO;

    cin >> m >> n;

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    memset(dp, 0x3f, sizeof dp);
    dp[1][1] = a[1][1];
    for(int j = 2; j <= n; j++) dp[1][j] = dp[1][j - 1] + a[1][j];
    for(int i = 2; i <= m; i++) dp[i][1] = dp[i - 1][1] + a[i][1];
    for(int i = 2; i <= m; i++){
        for(int j = 2; j <= n; j++){
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
        }
    }

    cout << dp[m][n];
    return 0;
}