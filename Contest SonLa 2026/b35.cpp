#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 3000005;

struct Data{
    ll g;
    int l;
};

ll gcd(ll a, ll b){
    while(b){
        a %= b;
        swap(a, b);
    }
    return a;
}

int n;
int a[MAXN];
Data dp1[40], dp2[40];

int main(){
    FAST_IO

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    ll res = 0;
    int sz = 0;
    for(int r = 1; r <= n; r++){
        int nsz = 0;
        dp2[nsz++] = {a[r], r};
        for(int i = 0; i < sz; i++){
            ll ng = gcd(dp1[i].g, a[r]);
            if(ng == dp2[nsz - 1].g){
                dp2[nsz - 1].l = min(dp2[nsz - 1].l, dp1[i].l);
            }
            else{
                dp2[nsz++] = {ng, dp1[i].l};
            }
        }

        sz = 0;
        for(int i = 0; i < nsz; i++){
            if(sz == 0 || dp1[sz - 1].g != dp2[i].g){
                dp1[sz++] = dp2[i];
            }
            else{
                dp1[sz - 1].l = min(dp1[sz - 1].l, dp2[i].l);
            }

            ll cur = (r - dp2[i].l + 1) * dp2[i].g;
            if(cur > res) res = cur;
        }
    }

    cout << res;

    return 0;
}