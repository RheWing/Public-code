#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 1e5 + 5;
const int NEG = -1e9;

int n;
int dp[6][6][6], ndp[6][6][6];

int main(){
    FAST_IO

    cin >> n;

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            for(int k = 0; k < 6; k++){
                dp[i][j][k] = NEG;
            }
        }
    }
    dp[0][0][0] = 0;

    for(int idx = 0; idx < n; idx++){
        int x; cin >> x;
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++){
                for(int k = 0; k < 6; k++){
                    ndp[i][j][k] = NEG;
                }
            }
        }

        for(int ls = 0; ls <= 5; ls++){
            for(int lm = 0; lm <= 5; lm++){
                for(int fm = 0; fm <= 5; fm++){
                    int cur = dp[ls][lm][fm];
                    if(cur == NEG) continue;
                    int g1 = ls ? (x - ls + 5) % 5 : 0;
                    ndp[x][lm][fm] = max(ndp[x][lm][fm], cur + g1);
                    int g2 = lm ? (x - lm + 5) % 5 : 0;
                    int nfm = lm ? fm : x;
                    ndp[ls][x][nfm] = max(ndp[ls][x][nfm], cur + g2);
                }
            }
        }
        memcpy(dp, ndp, sizeof(dp));
    }

    int best = 0;
    for(int ls = 0; ls <= 5; ls++){
        for(int lm = 0; lm <= 5; lm++){
            for(int fm = 0; fm <= 5; fm++){
                int cur = dp[ls][lm][fm];
                if(cur == NEG) continue;
                int junc = (ls && lm) ? (fm - ls + 5) % 5 : 0;
                best = max(best, cur + junc);   
            }
        }
    }

    cout << 1LL * n + best << "\n";
    return 0;
}