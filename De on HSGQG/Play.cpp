#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task "Play"

const int MAXN = 5000005;

int n, k;
int a[MAXN];
int dp[MAXN];

int main() {
    FAST_IO
    FILE_IO

    cin >> n >> k;

    for(int i = 1; i <= n; i++) cin >> a[i];

    deque<int> dq;

    dp[1] = a[1];
    dq.push_back(1);

    for(int i = 2; i <= n; i++){
        while(!dq.empty() && dq.front() < i - k){
            dq.pop_front();
        }
        dp[i] = a[i] + dp[dq.front()];
        while(!dq.empty() && dp[dq.back()] <= dp[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }

    cout << dp[n] << "\n";

    return 0;
}
