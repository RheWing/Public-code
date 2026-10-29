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

struct P{
    ll x, y;
};

int n;
ll x[MAXN], y[MAXN];
P v[MAXN * 2];

ll cross(P a, P b){
    return a.x * b.y - a.y * b.x;
}

int half(P a){
    return (a.y < 0 || (a.y == 0 && a.x < 0));
}

bool cmp(P a, P b){
    int ha = half(a), hb = half(b);

    if(ha != hb) return ha < hb;

    return cross(a, b) > 0;
}

ll C3(ll k){
    if(k < 3) return 0;
    return k * (k - 1) * (k - 2) / 6;
}

int main(){
    FAST_IO

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
    }

    ll m1 = n - 1;
    ll all4 = m1 * (m1 - 1) * (m1 - 2) * (m1 - 3) / 24;

    ll res = 0;

    for(int p = 1; p <= n; p++){
        int m = 0;

        for(int q = 1; q <= n; q++){
            if(q == p) continue;

            v[m++] = {x[q] - x[p], y[q] - y[p]};
        }

        sort(v, v + m, cmp);

        for(int i = 0; i < m; i++){
            v[i + m] = v[i];
        }

        ll bad = 0;
        int j = 1;

        for(int i = 0; i < m; i++){
            if(j < i + 1) j = i + 1;

            while(j < i + m && cross(v[i], v[j]) > 0){
                j++;
            }

            bad += C3(j - i - 1);
        }

        res += all4 - bad;
    }

    cout << res << '\n';

    return 0;
}