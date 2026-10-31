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

        vector<ll> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(ALL(a));

        ll median = a[n / 2];
        ll cost = 0;
        for(int i = 0; i < n; i++) cost += llabs(a[i] - median);

        cout << cost << ' ' << a[n - 1] - a[0] << '\n';
    }

    return 0;
} 