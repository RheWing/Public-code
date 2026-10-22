#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task "BANK"
#define MAXN 1005

vector<int> T[MAXN];

int main() {
    FAST_IO
    //FILE_IO

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int c, t;
        cin >> c >> t;
        if (t > MAXN) t = MAXN;
        T[t].push_back(c);
    }

    priority_queue<int> pq;
    ll total = 0;

    for (int t = MAXN; t >= 0; t--) {
        for (int c : T[t]) {
            pq.push(c);
        }
        if (!pq.empty()) {
            total += pq.top();
            pq.pop();
        }
    }

    cout << total << "\n";

    return 0;
}
