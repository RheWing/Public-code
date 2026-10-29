#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP", "r", stdin); freopen(task".OUT", "w", stdout);
#define task ""

const int MAXN = 5005;
const int INF = 2e9;

int n, x, y;
int a[MAXN], b[MAXN], c[MAXN], d[MAXN];
int dp[MAXN][MAXN];

int main(){
    FAST_IO

    cin >> n >> x >> y;

    for(int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++) dp[i][j] = INF;
    }

    dp[0][0] = 1;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n - i; j++){
            if(dp[i][j] == INF) continue;

            int dis = 0;

            for(int q = dp[i][j]; q <= n; q++){
                if(a[q] <= x + i && x + i <= b[q] && c[q] <= y + j && y + j <= d[q]){
                    dis = q;
                    break;
                }
            }

            if(dis == 0) continue;

            dp[i + 1][j] = min(dp[i + 1][j], dis + 1);
            dp[i][j + 1] = min(dp[i][j + 1], dis + 1);
        }
    }

    int res = 0;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(dp[i][j] != INF) res = max(res, i + j);
        }
    }

    cout << res;

    return 0;
}
