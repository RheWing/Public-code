#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task "MARIO"
#define MAXN 705
#define INF 1e9 + 7

struct Edge {
    int t;
    int w;
};

int n, m;
int dist[MAXN * MAXN];
vector<Edge> adj[MAXN * MAXN];

int main() {
    FAST_IO
    FILE_IO

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < m; j++) {
            int w; cin >> w;
            int u = j + (i - 1) * m;
            int v = u + 1;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            int w; cin >> w;
            int u = j + (i - 1) * m;
            int v = u + m;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
    }

    int total_nodes = n * m;
    for (int i = 1; i <= total_nodes; i++) dist[i] = INF;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [du, u] = pq.top();
        pq.pop();

        if (du > dist[u]) continue;

        for (const auto& e : adj[u]) {
            int v = e.t;
            int w = e.w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << dist[total_nodes] << "\n";

    return 0;
}