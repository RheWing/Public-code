#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task "PLANET"

const int MAXN = 200005;
const int MAXA = 100000;
const int LOG = 20;

int n, q;
int a[MAXN];
int spf[MAXA + 5];
vector<int> fac[MAXN];
int R[MAXN];
int cnt[MAXA + 5];
int up[MAXN][LOG];

void sieve(){
    for(int i = 2; i <= MAXA; i++){
        if(!spf[i]){
            spf[i] = i;
            if(1LL * i * i <= MAXA){
                for(int j = i * i; j <= MAXA; j += i){
                    if(!spf[j]) spf[j] = i;
                }
            }
        }
    }
}

vector<int> F(int x){
    vector<int> res;
    while(x > 1){
        int p = spf[x];
        res.push_back(p);
        while(x % p == 0) x /= p;
    }
    return res;
}

int main(){
    FAST_IO
    FILE_IO

    sieve();

    cin >> n >> q;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i + n] = a[i];
    }

    for(int i = 1; i <= 2 * n; i++) fac[i] = F(a[i]);

    int r = 0;
    for(int l = 1; l <= 2 * n; l++){
        while(r < 2 * n){
            bool ok = true;
            for(int p : fac[r + 1]){
                if(cnt[p]){
                    ok = false;
                    break;
                }
            }
            if(!ok) break;
            r++;
            for(int p : fac[r]) cnt[p]++;
        }
        R[l] = r;
        for(int p : fac[l]) cnt[p]--;
    }

    for(int i = 1; i <= 2 * n + 1; i++) up[i][0] = min(R[i] + 1, 2 * n + 1);

    up[2 * n + 1][0] = 2 * n + 1;

    for(int k = 1; k < LOG; k++){
        for(int i = 1; i <= 2 * n + 1; i++){
            up[i][k] = up[up[i][k - 1]][k - 1];
        }
    }

    vector<int> best(n + 1);
    for(int st = 1; st <= n; st++){
        int target = st + n - 1;
        int cur = st;
        int ans = 0;
        for(int k = LOG - 1; k >= 0; k--){
            if(up[cur][k] <= target){
                cur = up[cur][k];
                ans += (1 << k);
            }
        }
        best[st] = ans + 1;
    }

    while(q--){
        int l, r;
        cin >> l >> r;

        if(l <= r){
            int target = r;
            int cur = l;
            int ans = 0;
            for(int k = LOG - 1; k >= 0; k--){
                if(up[cur][k] <= target){
                    cur = up[cur][k];
                    ans += (1 << k);
                }
            }
            cout << ans + 1 << '\n';
        }
        else{
            int target = r + n;
            int cur = l;
            int ans = 0;
            for(int k = LOG - 1; k >= 0; k--){
                if(up[cur][k] <= target){
                    cur = up[cur][k];
                    ans += (1 << k);
                }
            }
            cout << ans + 1 << '\n';
        }
    }

    return 0;
}