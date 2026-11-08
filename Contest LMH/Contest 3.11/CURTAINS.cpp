#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP", "r", stdin); freopen(task".OUT", "w", stdout);
#define task "CURTAINS"

const int MAXN = 100005;
const int MAXV = 1e9;
const ll LIM = 1LL * MAXV * MAXN;

int n, q, k, d;

struct TStation {
    int x, v;
};

struct TInfo {
    ll gmax;
    int kmin;
};

TStation a[MAXN];
ll v[MAXN];
int x[MAXN], Left[MAXN];
TInfo g[MAXN];

bool cmp(const TStation &p, const TStation &q) {
    return p.x < q.x;
}

void Maximize(TInfo &Target, const TInfo &Value) {
    if (Target.gmax < Value.gmax || (Target.gmax == Value.gmax && Target.kmin > Value.kmin)) {
        Target = Value;
    }
}

void Enter() {
    cin >> n >> q;

    FOR(i, 1, n) cin >> a[i].x;
    FOR(i, 1, n) cin >> a[i].v;

    sort(a + 1, a + n + 1, cmp);

    v[0] = 0;

    FOR(i, 1, n) {
        v[i] = v[i - 1] + a[i].v;
        x[i] = a[i].x;
    }
}

void Init() {
    int i = n;

    FORD(j, n, 1) {
        while (i > 0 && x[j] - x[i] <= d) i--;
        Left[j] = i;
    }
}

TInfo Optimize(ll price) {
    g[0] = {0, 0};

    FOR(j, 1, n) {
        int i = Left[j];

        g[j] = {g[i].gmax + v[j] - v[i] - price, g[i].kmin + 1};

        Maximize(g[j], g[j - 1]);
    }

    return g[n];
}

ll Solve() {
    ll low = 0, high = LIM;

    while (low <= high) {
        ll mid = (low + high) / 2;
        TInfo res = Optimize(mid);

        if (res.kmin > k) low = mid + 1;
        else high = mid - 1;
    }

    if (low == 0) return v[n];

    TInfo res = Optimize(low);

    return res.gmax + low * k;
}

int main() {
    FAST_IO;

    Enter();

    while (q--) {
        cin >> k >> d;

        Init();

        cout << Solve() << '\n';
    }

    return 0;
}