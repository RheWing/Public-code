#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);

ll f(ll z, ll a, ll b, ll c){
    return min({a + z, 2 * c - 2 * z, b + c - z});
}

int main(){
    FAST_IO

    int t; cin >> t;
    while(t--){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll mxz = min({a, b, c / 2, d});
        ll l = 0, r = mxz;
        while(l < r){
            int mid = (l + r) / 2;
            if(f(mid + 1, a, b, c) > f(mid, a, b, c)) l = mid + 1;
            else r = mid;         
        }

        ll res = f(l, a, b, c) / 2;
        cout << res << '\n';
    }

    return 0;
}