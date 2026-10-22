#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task "CAPDOI"
#define MAXN 100005
#define InF 1e9 + 7

int t;

int main() {
    FAST_IO
    FILE_IO

    cin >> t;

    while(t--){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        ll hailong = (a / 2) + (c / 2) + min(b, d);
        ll res = hailong * 2;

        ll thua_a = a % 2;
        ll thua_c = c % 2;
        ll thua_b = b - min(b, d);
        ll thua_d = d - min(b, d);

        ll ghep_a_b = min(thua_a, thua_b);
        res += ghep_a_b;
        thua_a -= ghep_a_b;
        thua_b -= ghep_a_b;

        ll ghep_c_d = min(thua_c, thua_d);
        res += ghep_c_d;
        thua_c -= ghep_c_d;
        thua_d -= ghep_c_d;

        ll ghep_c_b = min(thua_a, thua_b);
        res += ghep_a_b;
        thua_a -= ghep_a_b;
        thua_b -= ghep_a_b;

        ll ghep_a_d = min(thua_c, thua_d);
        res += ghep_c_d;
        thua_c -= ghep_c_d;
        thua_d -= ghep_c_d;

        cout << res << '\n';
    }    

    return 0;
}