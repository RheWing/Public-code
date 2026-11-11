#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const ll MOD = 998244353;
const ll INV2 = 499122177; 

ll n;

int main(){
    FAST_IO

    cin >> n;

    ll T1 = (n % MOD) * (n % MOD) % MOD;;
    T1 = (T1 * ((n + 1) % MOD)) % MOD;
    T1 = (T1 * INV2) % MOD;

    ll T2 = 0;
    for(ll l = 1, r; l <= n; l = r + 1){
        r = n / (n / l);
        ll sum = (l + r) % MOD;
        ll cnt = (r - l + 1) % MOD;
        ll v = (n / l) % MOD;
        ll val = (sum * cnt) % MOD;
        val = (val * INV2) % MOD;
        ll x = (v * val) % MOD;
        T2 = (T2 + x) % MOD;
    }

    cout << (T1 - T2 + MOD) % MOD << '\n';

    return 0;
}