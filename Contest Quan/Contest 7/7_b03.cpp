#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 200005;
const ll MOD = 1000000007;
const ll INV2 = 500000004;

struct P{
    ll x, y;
};

int n;
ll x[MAXN], y[MAXN];
P v[MAXN];
ll res = 0;

ll norm(ll x){
    x %= MOD;
    if(x < 0) x += MOD;
    return x;
}

bool cmp(P a, P b){
    return a.x * b.y - a.y * b.x > 0;
}

int main(){
    FAST_IO

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
    }

    for(int i = 1; i <= n; i++){
        int m = 0;

        for(int j = 1; j <= n; j++){
            if(i == j) continue;

            ll dx = x[j] - x[i];
            ll dy = y[j] - y[i];

            if(dy > 0 || (dy == 0 && dx > 0)){
                v[m++] = {dx, dy};
            }
        }

        sort(v, v + m, cmp);

        ll sx = 0, sy = 0;

        for(int j = 0; j < m; j++){
            ll mx = norm(v[j].x);
            ll my = norm(v[j].y);

            res = (res + sx * my % MOD - sy * mx % MOD + MOD) % MOD;

            sx = (sx + mx) % MOD;
            sy = (sy + my) % MOD;
        }
    }

    cout << res * INV2 % MOD << '\n';

    return 0;
}