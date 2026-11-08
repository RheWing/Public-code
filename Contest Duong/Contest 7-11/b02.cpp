#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int N = 5005;
int n;
ll a[N];
ll pref[N];
ll dp[N][N];
int opt[N][N];

int main(){
    FAST_IO

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    pref[0] = 0;
    for(int i = 1; i <= n; i++){
        pref[i] = pref[i - 1] + a[i];
    }

    for(int i = 1; i <= n; i++){
        dp[i][i] = 0;
        opt[i][i] = i;
    }

    for(int len = 2; len <= n; len++){
        for(int l = 1; l + len - 1 <= n; l++){
            int r = l + len - 1;
            ll best = LLONG_MAX;
            int bk = l;
            for(int k = opt[l][r - 1]; k <= min(r - 1, opt[l + 1][r]); k++){
                ll v = dp[l][k] + dp[k + 1][r];
                if(v < best){
                    best = v;
                    bk = k;
                }
            }
            dp[l][r] = best + pref[r] - pref[l - 1];
            opt[l][r] = bk;
        }
    }

    cout << dp[1][n] << '\n';

    return 0;
}