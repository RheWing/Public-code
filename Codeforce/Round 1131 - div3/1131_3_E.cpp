#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

int main(){
    FAST_IO

    int t; cin >> t;
    while(t--){
        int n; cin >> n;

        vector<ll> b(n);
        for(int i = 1; i <= n; i++){
            ll x; cin >> x;
            b[i - 1] = (i % 2 == 0) ? x : -x;
        }

        sort(ALL(b));

        int o = (n + 1) / 2;
        ll res = 0;
        for(int i = 0; i < n; i++){
            if(i < o) res -= b[i];
            else res += b[i];
        }

        cout << res << '\n';
    }

    return 0;
}