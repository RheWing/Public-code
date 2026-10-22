#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".inp","r",stdin); freopen(task".out","w",stdout);
#define task "fire"
#define MAXN 205

const int INF = 1e9;

int n, k;
int h[MAXN], L[MAXN], R[MAXN], dp[MAXN];
pair<int, int> p[MAXN];

bool ok(int x){
    for(int i = 1; i <= n; i++) dp[i] = INF;
    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        p[i] = {max(L[i], i - x), min(R[i], i + x)};
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int u = p[j].first, v = p[j].second;
            if(v >= i && u - 1 >= 0 && dp[u - 1] != INF){
                dp[i] = min(dp[i], dp[u - 1] + 1);
            }
        }
        if(i > 1) dp[i] = min(dp[i], dp[i - 1] + 1);
    }
    return dp[n] <= k;
}

int main() {
    FAST_IO
    FILE_IO

    cin >> n >> k;

    for(int i = 1; i <= n; i++) cin >> h[i];
    for(int i = 1; i < n; i++){ 
        int tmp; cin >> tmp; 
    }

    for(int i = 1; i <= n; i++){
        L[i] = i;
        for(int j = i - 1; j >= 1; j--){
            L[i] = j;
            if(h[j] >= h[i]) break;
        }
        R[i] = i;
        for(int j = i + 1; j <= n; j++){
            R[i] = j;
            if(h[j] >= h[i]) break;
        }
    }

    int l = 0, r = n, ans = -1;
    while(l <= r){
        int m = l + (r - l) / 2;
        if(ok(m)){
            ans = m;
            r = m - 1;
        }else{
            l = m + 1;
        }
    }

    cout << ans << '\n';
    return 0;
}