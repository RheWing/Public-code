#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task "prime"

const ll MOD = 998244353;
const int MAXN = 1000005;
int n;
ll m;
int a[MAXN];

ll Pow(ll a, ll b){
    ll res = 1;
    while(b){
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

namespace Sub1{
    void solve(){
        int x = a[1];
        vector<int> cnt;

        for(int p = 2; p * p <= x; p++){
            if(x % p == 0){
                int c = 0;
                while(x % p == 0){
                    x /= p;
                    c++;
                }
                cnt.push_back(c);
            }
        }

        if(x > 1) cnt.push_back(1);

        int sum = 0;
        for(int x : cnt) sum += x;

        ll res = 1;

        for(int i = 1; i <= sum; i++) res = res * i % MOD;

        for(int x : cnt){
            ll tmp = 1;
            for(int i = 1; i <= x; i++){
                tmp = tmp * i % MOD;
            }
            res = res * Pow(tmp, MOD - 2) % MOD;
        }

        cout << res << '\n';
    }
}

namespace Sub2{
    const int MAXV = 5005;
    int cnt[MAXV];

    void solve(){
        int sum = 0;

        for(int i = 1; i <= n; i++){
            int x = a[i];
            for(int p = 2; p * p <= x; p++){
                while(x % p == 0){
                    cnt[p]++;
                    sum++;
                    x /= p;
                }
            }
            if(x > 1){
                cnt[x]++;
                sum++;
            }
        }

        ll res = 1;

        for(int i = 1; i <= sum; i++) res = res * i % MOD;

        for(int p = 2; p < MAXV; p++){
            if(cnt[p]){
                ll tmp = 1;
                for(int i = 1; i <= cnt[p]; i++) tmp = tmp * i % MOD;
                res = res * Pow(tmp, MOD - 2) % MOD;
            }
        }

        cout << res << '\n';
    }
}

namespace Sub3{
    void solve(){
        int cnt2 = 0;
        int cnt3 = 0;

        for(int i = 1; i <= n; i++){
            int x = a[i];
            while(x % 2 == 0){
                cnt2++;
                x /= 2;
            }
            while(x % 3 == 0){
                cnt3++;
                x /= 3;
            }
        }

        int sum = cnt2 + cnt3;
        ll fSum = 1;
        ll f2 = 1;
        ll f3 = 1;

        for(int i = 1; i <= sum; i++){
            fSum = fSum * i % MOD;
            if(i <= cnt2) f2 = f2 * i % MOD;
            if(i <= cnt3) f3 = f3 * i % MOD;
        }

        ll res = fSum;
        res = res * Pow(f2, MOD - 2) % MOD;
        res = res * Pow(f3, MOD - 2) % MOD;

        cout << res << '\n';
    }
}

int main(){
    FAST_IO
    FILE_IO

    cin >> n >> m;

    bool sub1 = (n == 1);
    bool sub2 = (n <= 500);
    bool sub3 = 1;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        int x = a[i];
        while(x % 2 == 0) x /= 2;
        while(x % 3 == 0) x /= 3;
        if(x != 1) sub3 = false;
    }

    if(sub1){
        Sub1::solve();
        return 0;
    }

    if(sub3){
        Sub3::solve();
        return 0;
    }

    if(sub2){
        Sub2::solve();
        return 0;
    }

    return 0;
}