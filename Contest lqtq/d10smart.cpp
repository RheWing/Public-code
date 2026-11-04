#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);

const int MAXN = 5e5 + 5;

int n, m, Q, K;
unsigned seed;
int a[MAXN];
vector<int> g[MAXN];

int deg[MAXN], topo[MAXN];
int adj[MAXN][6];
int timer;
ll sum[MAXN];

unsigned int next_rand() {
    seed ^= seed << 13;
    seed ^= seed >> 17;
    seed ^= seed << 5;
    return seed;
}

int main() {
    FAST_IO

    cin >> n >> m >> Q >> K >> seed;

    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    static queue<int> q;

    for (int u = 1; u <= n; u++) {
        deg[u] = g[u].size();
        if (deg[u] <= 5) q.push(u);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo[u] = ++timer;
        for (int v : g[u]) {
            deg[v]--;
            if (deg[v] == 5) q.push(v);
        }
    }

    for (int u = 1; u <= n; u++) {
        int cnt = 0;
        for (int v : g[u]) {
            if (topo[u] < topo[v]) {
                adj[u][++cnt] = v;
            }
        }
    }

    for (int u = 1; u <= n; u++) {
        for (int v : adj[u]) {
            sum[v] += a[u];
        }
    }

    ull XOR_SUM = 0;

    for (int i = 1; i <= Q; i++) {
        int type = (next_rand() % 2) + 1;
        int u = (next_rand() % K) + 1;

        if (type == 1) {
            unsigned x = (next_rand() % 1000000000) + 1;
            int delta = x - a[u];
            a[u] = x;
            for (int v : adj[u]) sum[v] += delta;
        } else {
            ll ans = sum[u];
            for (int i = 1; i <= 5; i++) ans += a[adj[u][i]];
            XOR_SUM ^= ans;
        }
    }

    cout << XOR_SUM << '\n';

    return 0;
}