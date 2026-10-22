#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);

const int MAXK = 100005;
const int MAXN = 105;
const int MOD = 1000000007;
int n, k;
int a[MAXN];
int dp[MAXK], ndp[MAXK], pref[MAXK];

int main(){
    FAST_IO;

    int n, k;
    cin >> n >> k;

    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }

    if(sum < k){
        cout << 0;
        return 0;
    }

    dp[0] = 1;

    for(int i = 0; i < n; i++){
        pref[0] = 0;
        for(int j = 0; j <= k; j++){
            pref[j + 1] = pref[j] + dp[j];
            if(pref[j + 1] >= MOD) pref[j + 1] -= MOD;
        }
        for(int j = 0; j <= k; j++){
            int l = max(0, j - a[i]);

            ndp[j] = pref[j + 1] - pref[l];
            if(ndp[j] < 0) ndp[j] += MOD;
        }

        for(int i = 0; i <= k; i++) swap(dp[i], ndp[i]);
    }

    cout << dp[k];

    return 0;
}