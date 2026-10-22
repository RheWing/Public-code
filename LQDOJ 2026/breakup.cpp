#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".inp","r",stdin); freopen(task".out","w",stdout);
#define task "breakup"

const int MAXN = 8005;

int m, n, q;
int a[MAXN][MAXN];

ll dp[10][10][10][10];

int main() {
    FAST_IO
    FILE_IO

    cin >> m >> n >> q;

    for(int i = 1; i <= q; i++){
        int t, b, l, r;
        cin >> t >> b >> l >> r;
        t--, b--, l--, r--;
        for(int j = t; j <= b; j++){
            for(int k = l; k <= r; k++){
                a[j][k] = (a[j][k] + 1) % 2;
            }
        }
    }

    if(a[0][0] == 1 || a[m - 1][n - 1] == 1){
        cout << 0 << '\n';
        return 0;
    }

    dp[0][0][0][0] = 1;

    for(int x1 = 0; x1 < m; x1++) {
        for(int y1 = 0; y1 < n; y1++){
            for(int x2 = 0; x2 < m; x2++){
                for(int y2 = 0; y2 < n; y2++){
                    if(dp[x1][y1][x2][y2] == 0) continue;
                    for(int dx1 = 0; dx1 <= 1; dx1++){
                        int dy1 = 1 - dx1;
                        int nx1 = x1 + dx1;
                        int ny1 = y1 + dy1;
                        if(nx1 >= m || ny1 >= n || a[nx1][ny1] == 1) continue;
                        for(int dx2 = 0; dx2 <= 1; dx2++){
                            int dy2 = 1 - dx2;
                            int nx2 = x2 + dx2;
                            int ny2 = y2 + dy2;
                            if(nx2 >= m || ny2 >= n || a[nx2][ny2] == 1) continue;
                            if(nx1 == nx2 && ny1 == ny2){
                                if(nx1 != (m - 1) || ny1 != (n - 1)){
                                    continue;
                                }
                            }
                            dp[nx1][ny1][nx2][ny2] += dp[x1][y1][x2][y2];
                        }
                    }

                }
            }
        }
    }
    cout << dp[m-1][n-1][m-1][n-1] / 2 << '\n';

    return 0;
}
