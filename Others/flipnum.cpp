#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".inp","r",stdin); freopen(task".out","w",stdout);
#define task "flipnum"
#define MAXN 0

ll n;

ll rev(ll n){
    ll res = 0;
    while(n > 0){
        int x = n % 10;
        res = res * 10 + x;
        n /= 10; 
    }
    return res;
}

int main() {
    FAST_IO
    FILE_IO
    
    cin >> n;

    if(n % 10 == 9) cout << rev(n + 2) << '\n';
    else cout << rev(n + 1) << '\n';

    return 0;
}
