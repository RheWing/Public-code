#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);

const ll INF = 2e18;

vector<ll> fibo;
map<pair<ll, int>, vector<ll>> memo;

void fibonaci() {
    fibo.push_back(1);
    fibo.push_back(2);

    while (1) {
        ll x = fibo[fibo.size() - 1] + fibo[fibo.size() - 2];
        if (x > INF) break;
        fibo.push_back(x);
    }

    reverse(ALL(fibo));
}

int get_msb(ll n) {
    if (n == 0) return -1;
    return 63 - __builtin_clzll(n);
}

vector<ll> dequy(ll n, int index) {
    if (n == 0) return {};

    if (memo.count({n, index})) return memo[{n, index}];

    int n_msb = get_msb(n);
    vector<ll> best_seq;
    bool found = 0;

    for (int i = index; i < fibo.size(); i++) {
        ll f = fibo[i];
        int f_msb = get_msb(f);

        if (f_msb < n_msb) break;

        ll next_n = n ^ f;
        vector<ll> cur = dequy(next_n, i + 1);

        if (next_n == 0 || !cur.empty()) {
            cur.push_back(f);
            if (!found || cur.size() < best_seq.size()) {
                best_seq = cur;
                found = 1;
            }

            if (f_msb == n_msb) break;
        }
    }

    return memo[{n, index}] = best_seq;
}

void solve() {
    ll n;
    cin >> n;

    vector<ll> base_seq = dequy(n, 0);

    if (base_seq.empty() && n != 0) {
        cout << -1 << '\n';
        return;
    }

    vector<ll> res;
    ll cur_xor = 0, cur_sum = 0;

    for (ll x : base_seq) {
        res.push_back(x);
        cur_xor ^= x;
        cur_sum += x;
    }

    cout << res.size() << '\n';

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << (i == res.size() - 1 ? '\n' : ' ');
    }
}

int main() {
    FAST_IO

    fibonaci();

    int t; cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}