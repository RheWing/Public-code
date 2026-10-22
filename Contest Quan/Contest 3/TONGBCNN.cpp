
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);

const int MAXA = 1000000;
const ll MOD = 998244353;
const ll INV2 = 499122177;

int n;
int mu[MAXA + 5];
bool is_prime[MAXA + 5];
vector<int> p;
ll f[MAXA + 5];
ll cnt[MAXA + 5];

void sieve(){
    fill(is_prime + 2, is_prime + MAXA + 1, true);
    mu[1] = 1;

    for(int i = 2; i <= MAXA; i++){
        if(is_prime[i]) {
            p.push_back(i);
            mu[i] = -1;
        }

        for(int p : p){
            if(1LL * i * p > MAXA){
                break;
            }

            is_prime[i * p] = false;

            if(i % p == 0){
                mu[i * p] = 0;
                break;
            } else{
                mu[i * p] = -mu[i];
            }
        }
    }

    for(int d = 1; d <= MAXA; d++){
        if(mu[d] != 0){
            for(int T = d; T <= MAXA; T += d){
                f[T] = (f[T] + 1LL * mu[d] * d) % MOD;
            }
        }
    }

    for(int T = 1; T <= MAXA; T++){
        f[T] = f[T] * T % MOD;

        if(f[T] < 0){
            f[T] += MOD;
        }
    }
}

int main() {
    FAST_IO

    sieve();

    cin >> n;

    ll sum = 0;
    int mx = 0;

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;

        cnt[a]++;
        sum = (sum + a) % MOD;
        mx = max(mx, a);
    }

    ll S_all = 0;

    for(int T = 1; T <= mx; T++){
        ll s_k = 0;

        for(int k = 1; k <= mx / T; k++){
            s_k = (s_k + 1LL * k * cnt[T * k]) % MOD;
        }

        ll s_k_sq = s_k * s_k % MOD;
        S_all = (S_all + f[T] * s_k_sq) % MOD;
    }

    ll res = (S_all - sum + MOD) % MOD;
    res = res * INV2 % MOD;

    cout << res << '\n';

    return 0;
}
