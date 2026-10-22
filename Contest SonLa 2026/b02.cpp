#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);

const int MAXN = 300005;
const ll INF = LLONG_MAX;

int n, k;
ll t[MAXN];
vector<vector<int>> ch;
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

int main() {
    FAST_IO

    cin >> n >> k;

    for (int i = 1; i <= n; i++) cin >> t[i];

    ch.resize(k + 1);

    for (int i = 1; i <= k; i++) {
        pq.push({t[i], i});
    }

    int nxt = k + 1;

    while (true) {
        ll T = pq.top().first;
        vector<int> nodes;

        while (!pq.empty() && pq.top().first == T) {
            nodes.push_back(pq.top().second);
            pq.pop();
        }

        int g = nodes.size();
        int m = n - nxt + 1;

        if (m < g) {
            vector<char> vis(ch.size(), 0);
            vector<int> st, res;

            for (int x : nodes) {
                if (!vis[x]) {
                    vis[x] = 1;
                    st.push_back(x);
                }
            }

            while (!st.empty()) {
                int u = st.back();
                st.pop_back();

                if (u <= k) {
                    res.push_back(u);
                } else {
                    for (int v : ch[u]) {
                        if (!vis[v]) {
                            vis[v] = 1;
                            st.push_back(v);
                        }
                    }
                }
            }

            sort(ALL(res));

            cout << T << '\n';

            for (int i = 0; i < (int)res.size(); i++) {
                cout << res[i] << (i + 1 == (int)res.size() ? '\n' : ' ');
            }

            return 0;
        }

        sort(ALL(nodes));
        nodes.erase(unique(ALL(nodes)), nodes.end());

        int id;

        if (nodes.size() == 1) {
            id = nodes[0];
        } else {
            id = ch.size();
            ch.push_back(nodes);
        }

        for (int j = 0; j < g; j++) {
            pq.push({T + t[nxt++], id});
        }
    }

    return 0;
}