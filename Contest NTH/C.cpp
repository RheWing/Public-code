#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);

const int MAXN = 200005;

int n, q;
ll a[MAXN], S;
unordered_map<ll, int> cnt;

int main() {
    FAST_IO

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        S ^= a[i];
        cnt[a[i]]++;
    }

    cin >> q;
    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int i;
            ll x;
            cin >> i >> x;

            cnt[a[i]]--;
            cnt[x]++;
            S ^= a[i] ^ x;
            a[i] = x;
        }
        else {
            cout << cnt[S] << '\n';
        }
    }

    return 0;
}
