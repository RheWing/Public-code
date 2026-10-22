#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".inp","r",stdin); freopen(task".out","w",stdout);
#define task ""
#define MAXN 105

struct Trace{
    int j;
    int k;
} par[MAXN][MAXN][MAXN];

char get(int pre, int cur){
    if(cur == pre - 1) return 'L';
    if(cur == pre) return 'D';
    return 'R';
}

int n, m;
int a[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN];

int main() {
    FAST_IO
    
    cin >> m >> n;

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    memset(dp, -1, sizeof dp);

    for(int j = 1; j <= n; j++){
        for(int k = 1; k <= n; k++){
            if(j != k) dp[1][j][k] = a[1][j] + a[1][k];
            else dp[1][j][k] = a[1][j];
        }
    }

    for(int i = 2; i <= m; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                for(int x = -1; x <= 1; x++){
                    int jj = j - x;
                    if(jj < 1 || jj > n) continue;
                    for(int y = -1; y <= 1; y++){
                        int kk = k - y;
                        if(kk < 1 || kk > n) continue;
                        if(dp[i - 1][jj][kk] == -1) continue;
                        int add;
                        if(j != k) add = a[i][j] + a[i][k];
                        else add = a[i][j];
                        if(dp[i - 1][jj][kk] + add > dp[i][j][k]){
                            dp[i][j][k] = dp[i - 1][jj][kk] + add;
                            par[i][j][k] = {jj, kk};
                        }
                    } 
                }
            }
        }
    }

    int res = -1;
    int J, K;

    for(int j = 1; j <= n; j++){
        for(int k = 1; k <= n; k++){
            if(dp[m][j][k] > res){
                res = dp[m][j][k];
                J = j;
                K = k;
            }
        }
    }

    int x = m;
    int j = J;
    int k = K;
    string p1, p2;

    while(x > 1){
        int pj = par[x][j][k].j;
        int pk = par[x][j][k].k;
        p1.push_back(get(pj, j));
        p2.push_back(get(pk, k));

        j = pj;
        k = pk;
        x--;
    }

    reverse(ALL(p1));
    reverse(ALL(p2));

    cout << res << '\n';
    cout << j << ' ' << k << '\n';
    cout << p1 << '\n';
    cout << p2 << '\n';

    return 0;
}
