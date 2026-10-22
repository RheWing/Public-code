#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 2005;
const ll INF = LLONG_MAX;

int n, m;
int a[MAXN], b[MAXN];
ll dp[MAXN][MAXN];

int main(){
    FAST_IO

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i]--;
    }
    for(int i = 1; i <= m; i++){
        cin >> b[i];
        b[i]--;
    }

    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            ll best = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            dp[i][j] = best + a[i] * b[j];
        }
    }

    cout << dp[n][m];

    return 0;
}