#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 32768;

int n;
int a[MAXN], b[MAXN];
bool inA[MAXN], inB[MAXN];
int tgt[MAXN], own[MAXN];
pair<int, int> ans[MAXN * 20];
int cnt;

int main() {
    FAST_IO

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        inA[a[i]] = true;
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        inB[b[i]] = true;
    }

    int S[MAXN], T[MAXN];
    int szS = 0, szT = 0;

    for (int i = 1; i <= n; i++) {
        if (!inB[a[i]]) S[szS++] = a[i];
    }

    for (int i = 1; i <= n; i++) {
        if (!inA[b[i]]) T[szT++] = b[i];
    }

    for (int i = 0; i < szS; i++) {
        tgt[S[i]] = T[i];
        own[T[i]] = S[i];
    }

    while (szS > 0) {
        int x = S[--szS];
        int b0 = tgt[x];

        int p[20], szP = 1;
        p[0] = x;

        int cur = x;

        for (int bit = 0; bit < 15; bit++) {
            if (((cur ^ b0) >> bit) & 1) {
                cur ^= (1 << bit);
                p[szP++] = cur;

                if (!inA[cur]) break;
            }
        }

        for (int i = szP - 1; i >= 1; i--) ans[++cnt] = {p[i - 1], p[i]};

        int pj = p[szP - 1];

        inA[x] = false;
        inA[pj] = true;

        if (pj == b0) {
        } else if (inB[pj]) {
            int x2 = own[pj];
            tgt[x2] = b0;
            own[b0] = x2;
        } else {
            tgt[pj] = b0;
            own[b0] = pj;
            S[szS++] = pj;
        }
    }

    cout << cnt << '\n';

    for (int i = 1; i <= cnt; i++) cout << ans[i].first << ' ' << ans[i].second << '\n';

    return 0;
}