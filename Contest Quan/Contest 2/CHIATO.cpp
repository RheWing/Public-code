#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const ll INF = LLONG_MAX;

int n, k;
vector<ll> a;
vector<vector<ll>> w;
vector<ll> pre, cur;

void solve(int l, int r, int optl, int optr){
    if(l > r) return;
    int m = (l + r) / 2;
    ll best = INF;int bestj = optl;
    for(int j = optl; j <= min(m - 1, optr); j++){
        if(pre[j] == INF) continue;
        ll v = pre[j] + w[m - j][j];
        if(v < best){
            best = v;
            bestj = j;
        }
    }
    cur[m] = best;
    solve(l, m - 1, optl, bestj);
    solve(m + 1, r, bestj, optr);
}

int main(){
    FAST_IO

    cin >> n >> k;

    a.resize(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    w.resize(n + 1);
    for(int len = 0; len <= n; len++) w[len].resize(n - len + 1, 0);

    for(int len = 2; len <= n; len++){
        for(int l = 0; l + len <= n; l++){
            int r = l + len - 1;
            w[len][l] = w[len - 1][l + 1] + w[len - 1][l] - (len >= 3 ? w[len - 2][l + 1] : 0) + (a[l] ^ a[r]);
        }
    }

    int m = k + 1;
    pre.resize(n + 1, INF);
    cur.resize(n + 1, INF);

    for(int i = 1; i <= n; i++) pre[i] = w[i][0];
    pre[0] = INF;

    for(int t = 2; t <= m; t++){
        fill(cur.begin(), cur.end(), INF);
        solve(t, n, t - 1, n - 1);
        swap(pre, cur);
    }

    cout << pre[n];

    return 0;
}