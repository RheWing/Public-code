#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 100005;
int n;
int a[MAXN], cnt[MAXN];
ll dp[MAXN];

int main(){
    FAST_IO

    cin >> n;

    int mx = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        cnt[a[i]]++;
        mx = max(mx, a[i]);
    }

    dp[1] = 1LL * cnt[1];
    dp[2] = max(dp[1], 2LL * cnt[2]);

    for(int i = 3; i <= mx; i++){
        dp[i] = max(dp[i - 1], dp[i - 2] + 1LL * i * cnt[i]);
    }

    cout << dp[mx] << '\n';

    return 0;
}
