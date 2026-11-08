#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 20;
const int MAXA = 1000005;
int n, m;
int a[MAXN], prime[MAXA], b[MAXN], sum[1 <<MAXN];
int f[1 << MAXN][MAXN];

void sang(){
    prime[0] = prime[1] = 1;
    for(int i = 2; i * i < MAXA; i++){
        if(prime[i] == 0){
            for(int j = i * i; j < MAXA; j += i){
                prime[j] = 1;
            }
        }
    }
}

int find(int v){
    int resl = 0, resr = 0;
    for(int i = v - 1; i >= 2; i--){
        if(prime[i] == 0){
            resl = i;
            break;
        }
    }
    for(int i = v + 1; i <= 1000000; i++){
        if(prime[i] == 0){
            resr = i;
            break;
        }
    }
    if(resl == 0) return resr - v;
    if(resr == 0) return v - resl;
    return min(resr - v, v - resl);
}

int main(){
    FAST_IO

    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];

    sang();

    for(int i = 1; i <= n; i++){
        b[i] = find(a[i]);
    }

    for(int mask = 1; mask < (1 << n); mask++){
        int i = __builtin_ctz(mask) + 1;
        int pre = mask ^ (1 << (i - 1));
        sum[mask] = sum[pre] + b[i];
    }

    for(int mask = 0; mask < (1 << n); mask++){
        for(int i = 0; i <= m; i++){
            f[mask][i] = 1e9;
        }
    }

    f[0][0] = 0;
    for(int mask = 0; mask < (1 << n); mask++){
        for(int mask2 = mask; mask2 > 0; mask2 = mask & (mask2 - 1)){
            for(int j = 1; j <= m; j++){
                f[mask][j] = min(f[mask][j], max(f[mask - mask2][j - 1], sum[mask2]));
            }
        }
    }

    cout << f[(1 << n) - 1][m];

    return 0;
}