#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 8005;
const ll INF = LLONG_MAX;

int l, g;
ll p[MAXN];
ll predp[MAXN], curdp[MAXN];

ll get(int i, int j){
    return (ll)(i - j) * (p[i] - p[j]);
}

void solve(int l, int r, int nl, int nr){
    if(l > r) return;
    int m = (l + r) / 2;
    ll best = INF;
    int bestj = -1;
    for(int j = nl; j <= min(m - 1, nr); j++){
        if(predp[j] == INF) continue;
        ll v = predp[j] + get(j, m);
        if(v < best){
            best = v;
            bestj = j;
        }
    }
    curdp[m] = best;
    if(bestj == -1) bestj = nl;
    solve(l, m - 1, nl, bestj);
    solve(m + 1, r, bestj, nr);
}

int main(){
    FAST_IO

    cin >> l >> g;

    for(int i = 1; i <= l; i++){
        ll c;
        cin >> c;
        p[i] = p[i - 1] + c;
    }

    for(int i = 1; i <= l; i++) predp[i] = get(0, i);
    predp[0] = INF;

    for(int i = 2; i <= g; i++){
        for(int j = 0;j <= l; j++) curdp[j] = INF;
        solve(1, l, 0, l - 1);
        for(int k = 0; k <= l; k++) predp[k] = curdp[k];
    }

    cout << predp[l];

    return 0;
}