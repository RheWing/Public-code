#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".inp","r",stdin); freopen(task".out","w",stdout);
#define task "sums"
#define MAXN 75

const ll INF = 5e18;

int n, sum;
int a[MAXN], c[MAXN][MAXN * 1000];
ll dp[MAXN * 1000];

int main() {
    FAST_IO
    FILE_IO
    
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }

    sort(a + 1, a + n + 1);

    dp[0] = 1;

    for(int i = 1; i <= n; i++){
        for(int s = sum - a[i]; s >= 0; s--){
            if(dp[s] == 0) continue;
            dp[s + a[i]] = min(INF, dp[s + a[i]] + dp[s]);
        }
    }

    ll cnt_sum = 0;
    ll b_cnt = 0;
    ll b_sum = 0;

    for(int s = 1; s <= sum; s++){
        if(dp[s]) cnt_sum++;
        if(dp[s] > b_cnt){
            b_cnt = dp[s];
            b_sum = s;
        }
        else if(dp[s] == b_cnt && s > b_sum){
            b_sum = s;
        }
    }

    c[n + 1][0] = 1;
    for(int i = n; i >= 1; i--){
        for(int s = 0; s <= sum; s++){
            c[i][s] = c[i + 1][s];
            if(s >= a[i] && c[i + 1][s - a[i]]) c[i][s] = 1;
        }
    }

    cout << cnt_sum << '\n';
    cout << b_sum << ' ' << b_cnt << '\n';

    ll d = b_sum;

    for(int i = 1; i <= n && d; i++){
        if(d >= a[i] && c[i + 1][d - a[i]]){
            cout << a[i] << ' ';
            d -= a[i];
        }
    }

    cout << '\n';

    return 0;
}
