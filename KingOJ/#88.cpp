
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const ll MOD = 1e9 + 7;
const ll PHI = MOD - 1;

ll power(ll a, ll b, ll mod = MOD){
    ll res = 1;
    while(b){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main(){
    FAST_IO

    int k;
    cin >> k;

    ll p[100005], e[100005], cnt = 1, n = 1;

    for(int i = 1; i <= k; i++){
        cin >> p[i] >> e[i];
        n = n * power(p[i], e[i]) % MOD;
        cnt = cnt * (e[i] + 1) % PHI;
    }

    ll res = 1;
    if(cnt % 2 == 0) res = power(n, cnt / 2);
    else{
        for(int i = 1; i <= k; i++){
            if(e[i] % 2 == 0){
                res = power(n, cnt / 2);
                break;
            }
        }
    }

    cout << res;
    return 0;
}
