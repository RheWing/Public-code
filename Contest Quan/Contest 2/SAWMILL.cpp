#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task "SAWMILL"

const int MAXN = 100005;

int n;
ll s[MAXN], w[MAXN], W[MAXN], WS[MAXN], dp[MAXN], d[MAXN], m[MAXN], b[MAXN];
int h = 0, t = 0;

ll get(int k, ll x){
    return m[k] * x + b[k];
}

void add(ll M, ll B){
    while(t - h >= 2){
        int l1 = t - 2, l2 = t - 1;
        if((__int128)(B - b[l1]) * (m[l1]- m[l2]) <= (__int128)(b[l2] - b[l1]) * (m[l1] - M)) t--;
        else break;
    }
    m[t] = M;
    b[t] = B;
    t++;
}

ll query(ll x){
    while(t - h >= 2 && get(h + 1, x) <= get(h, x)) h++;
    return get(h, x);
}

int main(){
    FAST_IO

    cin >> n;

    for(int i = 1; i <= n; i++) cin >> w[i] >> d[i];

    s[1] = 0;
    for(int i = 1; i <= n; i++) s[i + 1] = s[i] + d[i];
    for(int i = 1; i <= n; i++){
        W[i] = W[i - 1] + w[i];
        WS[i] = WS[i - 1] + w[i] * s[i];
    }

    for(int i = 1; i <= n; i++) dp[i] = s[i] * W[i - 1] - WS[i - 1];

    ll res = LLONG_MAX;
    for(int j = 2;j <= n; j++){
        int i = j - 1;
        add(-W[i], dp[i] + WS[i]);
        ll f = query(s[j]);
        ll cij = s[j] * W[j - 1] - WS[j - 1];
        ll cjend = s[n + 1] * (W[n] - W[j]) - (WS[n] - WS[j]);
        res = min(res, f + cij + cjend);
    }

    cout << res;

    return 0;
}