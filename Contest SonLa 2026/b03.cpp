#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

int n, k;
string s, t;

int main(){
    FAST_IO;

    cin >> n >> k;

    cin >> s >> t;

    vector<ll> f(n + 2, 0), d(n + 2, 0);

    ll ps = 0, pt = 0;
    for(int i = 1; i < n; i++){
        ps += s[i - 1] - '0';
        pt += t[i - 1] - '0';
        f[i] = ps - pt; 
    }

    ll res = 0;
    int i = 1;
    while(i < n){
        if(f[i] == 0){
            i++;
            continue;
        }
        int j = i;
        while(j + 1 < n && f[j + 1] != 0 && (f[j + 1] > 0) == (f[i] > 0)) j++;
        ll c = 0;
        for(int x = i; x <= j; x++){
            c += d[x];
            ll need = llabs(f[x]);
            if(need > c) {
                ll z = need - c;
                res += z;
                c += z;
                if(x + k <= j) d[x + k] -= z;
            }
        }
        i = j + 1;
    }

    cout << res;
    return 0;
}