
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);

const int MAXN = 200005;

struct Rect {
    int a, b, c, d, id;
};

struct BIT {
    int n;
    vector<int> t;

    void init(int sz) {
        n = sz;
        t.assign(n + 1, 0);
    }

    void update(int x, int v) {
        for(; x <= n; x += x & -x) t[x] += v;
    }

    int query(int x) {
        int res = 0;
        for(; x > 0; x -= x & -x) res += t[x];
        return res;
    }
};

int n;
Rect a[MAXN];
vector<int> X, Y;
BIT bitB, bitD;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

bool cmp(Rect x, Rect y) {
    if(x.a != y.a) return x.a < y.a;
    return x.id < y.id;
}

int main() {
    FAST_IO

    int T;
    cin >> T;

    while(T--) {
        cin >> n;

        X.clear();
        Y.clear();

        while(!pq.empty()) pq.pop();

        for(int i = 1; i <= n; i++) {
            cin >> a[i].a >> a[i].b >> a[i].c >> a[i].d;
            a[i].id = i;
            X.push_back(a[i].b);
            Y.push_back(a[i].d);
        }

        sort(a + 1, a + n + 1, cmp);

        sort(X.begin(), X.end());
        X.erase(unique(X.begin(), X.end()), X.end());

        sort(Y.begin(), Y.end());
        Y.erase(unique(Y.begin(), Y.end()), Y.end());

        bitB.init(X.size());
        bitD.init(Y.size());

        ll ans = 0;

        for(int i = 1; i <= n; i++) {
            while(!pq.empty() && pq.top().first < a[i].a) {
                int id = pq.top().second;
                pq.pop();

                int x = lower_bound(X.begin(), X.end(), a[id].b) - X.begin() + 1;
                int y = lower_bound(Y.begin(), Y.end(), a[id].d) - Y.begin() + 1;

                bitB.update(x, -1);
                bitD.update(y, -1);
            }

            int x = upper_bound(X.begin(), X.end(), a[i].d) - X.begin();
            int y = lower_bound(Y.begin(), Y.end(), a[i].b) - Y.begin();

            ans += bitB.query(x) - bitD.query(y);

            int u = lower_bound(X.begin(), X.end(), a[i].b) - X.begin() + 1;
            int v = lower_bound(Y.begin(), Y.end(), a[i].d) - Y.begin() + 1;

            bitB.update(u, 1);
            bitD.update(v, 1);

            pq.push({a[i].c, i});
        }

        cout << ans << '\n';
    }

    return 0;
}
