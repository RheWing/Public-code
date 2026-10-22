
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MOD = 1e9 + 7;
const int MAXN = 5005;

int n, m;

namespace Subtask1{
    void solve(int n, int m, const vector<int>& cnt){
        ll ans = 0;

        if(m == 1){
            cout << 1 << '\n';
            return;
        }
        if(m == 2){
            cout << (cnt[1] % 3 == 0 && cnt[2] % 3 == 0) << '\n';
            return;
        }
        if(m == 3){
            for(int k = 0; k <= min({cnt[1], cnt[2], cnt[3]}); k++){
                if((cnt[1] - k) % 3 == 0 &&
                   (cnt[2] - k) % 3 == 0 &&
                   (cnt[3] - k) % 3 == 0){
                    ans++;
                }
            }

            cout << ans % MOD << '\n';
            return;
        }

        for(int c1 = 0; c1 <= cnt[1]; c1++){
            for(int c2 = 0; c2 <= cnt[4]; c2++){
                if(c1 + c2 > cnt[2] || c1 + c2 > cnt[3]){
                    continue;
                }

                if((cnt[1] - c1) % 3 == 0 &&
                   (cnt[2] - c1 - c2) % 3 == 0 &&
                   (cnt[3] - c1 - c2) % 3 == 0 &&
                   (cnt[4] - c2) % 3 == 0){
                    ans = (ans + 1) % MOD;
                }
            }
        }

        cout << ans << '\n';
    }
}

namespace Subtask2{
    int dp[MAXN][3][3];

    void solve(int n, int m, const vector<int>& cnt){
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;

        for(int i = 1; i <= m; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    int p = cnt[i] - j - k;

                    if(p < 0 || p > 2){
                        continue;
                    }

                    dp[i][j][k] = dp[i - 1][p][j];
                }
            }
        }

        cout << dp[m][0][0] << '\n';
    }
}

namespace subfull{
    void solve(int n, int m, const vector<int>& cnt){
        vector<vector<int>> dp(1, vector<int>(1, 1));

        int p = 0, q = 0;

        for(int i = 1; i <= m + 2; i++){
            int c = cnt[i];

            vector<vector<int>> ndp(c + 1, vector<int>(p + 1, 0));

            for(int x = 0; x <= p; x++){
                for(int y = 0; y <= q; y++){
                    int val = dp[x][y];
                    if(val == 0){
                        continue;
                    }
                    for(int z = 0; z <= c - x; z++){
                        int rem = c - x - z;

                        if(rem < 0 || rem > q){
                            continue;
                        }
                        if(rem % 3 != y % 3){
                            continue;
                        }
                        ndp[z][x] = (ndp[z][x] + val) % MOD;
                    }
                }
            }

            dp.swap(ndp);
            q = p;
            p = c;
        }

        cout << dp[0][0] << '\n';
    }
}

int main(){
    FAST_IO

    cin >> n >> m;

    vector<int> cnt(m + 3, 0);

    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        cnt[a]++;
    }

    bool is_sub2 = true;

    for(int i = 1; i <= m; i++){
        if(cnt[i] > 2){
            is_sub2 = false;
        }
    }

    if(m <= 4){
        Subtask1::solve(n, m, cnt);
    }
    else if(is_sub2){
        Subtask2::solve(n, m, cnt);
    }
    else{
        subfull::solve(n, m, cnt);
    }

    return 0;
}
