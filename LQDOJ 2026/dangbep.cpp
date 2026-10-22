#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task "dangbep"

const ll INF = 4e18;
const ll MOD = 1019972207LL;
int m, n, x, y;
string a[25];
ll dp[305][26][305];
ll w[305][26][305];
int costCol[305][26];
ll wayCol[305][26];
ll C[25][25];

int main(){
    FAST_IO
    FILE_IO

    cin >> m >> n >> x >> y;

    for(int i = 0; i < m; i++) cin >> a[i];

    for(int i = 0; i <= 20; i++){
        C[i][0] = C[i][i] = 1;
        for(int j = 1; j < i; j++) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }

    for(int col = 1; col <= n; col++){
        int cnt[26] = {};

        for(int row = 0; row < m; row++) cnt[a[row][col - 1] - 'a']++;

        for(int c = 0; c < 26; c++){
            int need = max(0, m - 1 - cnt[c]);
            costCol[col][c] = need;
            wayCol[col][c] = C[m - cnt[c]][need];
        }
    }

    for(int i = 0; i <= n; i++){
        for(int c = 0; c < 26; c++){
            for(int len = 0; len <= y; len++){
                dp[i][c][len] = INF;
                w[i][c][len] = 0;
            }
        }
    }

    for(int c = 0; c < 26; c++){
        dp[1][c][1] = costCol[1][c];
        w[1][c][1] = wayCol[1][c] % MOD;
    }

    for(int i = 1; i < n; i++){
        for(int c = 0; c < 26; c++){
            for(int len = 1; len <= y; len++){
                if(dp[i][c][len] == INF) continue;

                if(len < y){
                    ll ncost = dp[i][c][len] + costCol[i + 1][c];
                    ll nway = w[i][c][len] * wayCol[i + 1][c] % MOD;

                    if(ncost < dp[i + 1][c][len + 1]){
                        dp[i + 1][c][len + 1] = ncost;
                        w[i + 1][c][len + 1] = nway;
                    }
                    else if(ncost == dp[i + 1][c][len + 1]){
                        w[i + 1][c][len + 1] += nway;
                        w[i + 1][c][len + 1] %= MOD;
                    }
                }

                if(len >= x){
                    for(int d = 0; d < 26; d++){
                        if(d == c) continue;

                        ll ncost = dp[i][c][len] + costCol[i + 1][d];
                        ll nway = w[i][c][len] * wayCol[i + 1][d] % MOD;

                        if(ncost < dp[i + 1][d][1]){
                            dp[i + 1][d][1] = ncost;
                            w[i + 1][d][1] = nway;
                        }
                        else if(ncost == dp[i + 1][d][1]){
                            w[i + 1][d][1] += nway;
                            w[i + 1][d][1] %= MOD;
                        }
                    }
                }
            }
        }
    }

    ll res = INF;
    ll cntres = 0;

    for(int c = 0; c < 26; c++){
        for(int len = x; len <= y; len++){
            if(dp[n][c][len] < res){
                res = dp[n][c][len];
                cntres = w[n][c][len];
            }
            else if(dp[n][c][len] == res){
                cntres += w[n][c][len];
                cntres %= MOD;
            }
        }
    }

    cout << res << ' ' << cntres % MOD;
    return 0;
}