#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP", "r", stdin); freopen(task".OUT", "w", stdout);
#define task ""

const int MAXN = 200005;

int n;
ll x;
vector<ll> d, f, P, F, g, R;

int check(int D) {
    int h = n / 2;
    fill(ALL(R), 0);

    for (int k = 1; k < D; k++) {
        ll need = P[k + 1] - x - F[k];
        int m = min(k, n - k);
        R[m] = max(R[m], need);
    }

    priority_queue<ll> pq;
    ll sum = 0;
    int cnt = 0;

    for (int m = 1; m <= h; m++) {
        if (g[m] > 0) pq.push(g[m]);
        while (sum < R[m]) {
            if (pq.empty()) return -1;
            sum += pq.top();
            pq.pop();
            cnt++;
        }
    }

    return cnt;
}

int main() {
    FAST_IO

    cin >> n >> x;

    d.assign(n + 2, 0);
    f.assign(n + 2, 0);
    P.assign(n + 2, 0);
    F.assign(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        P[i] = P[i - 1] + d[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> f[i];
        F[i] = F[i - 1] + f[i];
    }

    g.assign(n / 2 + 2, 0);
    R.assign(n / 2 + 2, 0);
    for (int i = 1; i <= n / 2; i++) {
        g[i] = f[n + 1 - i] - f[i];
    }

    int lo = 1, hi = n;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (check(mid) != -1) lo = mid;
        else hi = mid - 1;
    }

    cout << lo << " " << check(lo) << '\n';

    return 0;
}
