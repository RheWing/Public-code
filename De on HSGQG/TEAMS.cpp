#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task "TEAMS"

const int MAXN = 100005;
const int MOD = 1e9 + 7;

int n;
ll a[MAXN];
ll pow2[MAXN];

void p(){
    pow2[0] = 1;
    for(int i = 1; i <= MAXN; i++){
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    }
}

int main() {
    FAST_IO
    FILE_IO

    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];
    
    sort(a + 1, a + n + 1);
    p();

    ll res = 0;
    for(int i = 2; i <= n; i++){
        res += (((a[1] * a[i]) % MOD) * pow2[n - i]) % MOD; 
    }
    res = (res * 2) % MOD;

    cout << res << '\n';
    
    return 0;
}
