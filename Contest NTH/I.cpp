#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 500005;

struct BIT {
    int n, LOG;
    vector<int> t;

    void init(int n_) {
        n = n_;
        t.assign(n + 1, 0);
        LOG = 1;
        while ((1 << LOG) <= n) LOG++;
    }

    void add(int i, int v) {
        for (; i <= n; i += i & -i) t[i] += v;
    }

    int kth(int k) {
        int pos = 0;
        for (int b = LOG; b >= 0; b--) {
            int np = pos + (1 << b);
            if (np <= n && t[np] < k) {
                pos = np;
                k -= t[np];
            }
        }
        return pos + 1;
    }
};

int q, nr, nc;
ll c;
int opt[MAXN], X[MAXN], Y[MAXN];
int N[2], posOf[MAXN], origPos[2];
int timeAt[2][MAXN];
ll valAt[2][MAXN];
BIT bit[2];

int main() {
    FAST_IO

    cin >> q >> c;

    for (int i = 1; i <= q; i++) {
        cin >> opt[i] >> X[i] >> Y[i];
        if (opt[i] == 1) nr++;
        else if (opt[i] == 2) nc++;
    }

    N[0] = nr + 1;
    N[1] = nc + 1;

    for (int d = 0; d < 2; d++) {
        bit[d].init(N[d]);
        for (int i = 1; i <= N[d]; i++) bit[d].add(i, 1);
    }

    for (int i = q; i >= 1; i--) {
        if (opt[i] == 3) continue;
        int d = opt[i] - 1;
        int p = bit[d].kth(X[i] + 1);
        bit[d].add(p, -1);
        posOf[i] = p;
    }

    for (int d = 0; d < 2; d++) origPos[d] = bit[d].kth(1);

    for (int d = 0; d < 2; d++) {
        for (int i = 1; i <= N[d]; i++) valAt[d][i] = c;
    }

    for (int i = 1; i <= q; i++) {
        if (opt[i] == 3) continue;
        int d = opt[i] - 1;
        timeAt[d][posOf[i]] = i;
        valAt[d][posOf[i]] = Y[i];
    }

    for (int d = 0; d < 2; d++) {
        bit[d].init(N[d]);
        bit[d].add(origPos[d], 1);
    }

    for (int i = 1; i <= q; i++) {
        if (opt[i] == 3) {
            int pr = bit[0].kth(X[i]);
            int pc = bit[1].kth(Y[i]);
            if (timeAt[0][pr] >= timeAt[1][pc]) cout << valAt[0][pr] << '\n';
            else cout << valAt[1][pc] << '\n';
        } else {
            int d = opt[i] - 1;
            bit[d].add(posOf[i], 1);
        }
    }

    return 0;
}
