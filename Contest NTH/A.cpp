#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);

const ll MOD = 1000000007;
const ll INV3 = 333333336;

ll POW(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    FAST_IO

    ll n;
    cin >> n;

    ll k = n + 1;
    ll pw = POW(2, k);
    ll r = (k % 2 == 0 ? 1 : 2);

    ll res = (pw - r + MOD) % MOD;
    res = res * INV3 % MOD;

    cout << res;

    return 0;
}