#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);

const int MAXN = 50;
const int MAX_SUM = 5000000; 

int n;
ll a[MAXN + 1], b[MAXN + 1];

int main(){
    FAST_IO

    cin >> n;

    ll sum_b = 0;
    ll max_s1 = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
        sum_b += b[i];     
        max_s1 += a[i];    
    }

    vector<ll> dp(max_s1 + 1, 1e18);
    dp[0] = sum_b; 

    for(int i = 1; i <= n; i++){
        for(int j = max_s1; j >= 0; j--){
            if(j >= a[i] && dp[j - a[i]] != 1e18){
                dp[j] = min(dp[j], dp[j - a[i]] - b[i]);
            }
        }
    }

    ll res = 1e18;
    for(int j = 0; j <= max_s1; j++){
        if(dp[j] != 1e18){
            ll cur_max = max((ll)j, dp[j]);
            res = min(res, cur_max);
        }
    }

    cout << res;

    return 0;
}
