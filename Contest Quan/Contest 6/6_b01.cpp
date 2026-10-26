#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

ll n, a, b, c;

int main(){
    FAST_IO

    cin >> n >> a >> b >> c;

    ll pos = 0, neg = 0;
    for(ll i = 0; i < n; i++){
        ll x, y;
        cin >> x >> y;
        ll f = a * x + b * y + c;
        if(f > 0) pos++;
        else if (f < 0) neg++;
    }

    cout << pos * neg << '\n';

    return 0;
}