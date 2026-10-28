#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 50;
const int INF = 1e9;

int n, a[MAXN + 1], b[MAXN + 1];

int main(){
    FAST_IO

    cin >> n;

    int sum_b = 0, sum_a = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
        sum_a += a[i];
        sum_b += b[i];
    }

    vector<int> dp(sum_a + 1, INF);
    dp[0] = sum_b;

    int cur_sum = 0;
    for(int i = 1; i <= n; i++){
        for(int j = cur_sum; j >= 0; j--){
            if(dp[j] == INF) continue;
            dp[j + a[i]] = min(dp[j + a[i]], dp[j] - b[i]);
        }
        cur_sum += a[i];
    }

    int res = INF;
    for(int j = 0; j <= sum_a; j++){
        if(dp[j] != INF){
            res = min(res, max(j, dp[j]));
        }
    }

    cout << res;
    return 0;
}
