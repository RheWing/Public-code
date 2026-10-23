#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

int n, q;

int main() {
    FAST_IO

    cin >> n >> q;

    vector<int> mn(2 * n), mx(2 * n);
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        mn[n + v] = mx[n + v] = i; 
    }
    for (int i = n - 1; i >= 1; i--) {
        mn[i] = min(mn[2 * i], mn[2 * i + 1]);
        mx[i] = max(mx[2 * i], mx[2 * i + 1]);
    }

    int X = 0;
    while (q--) {
        string t;
        cin >> t;
        if (t == "Update") {
            int x;
            cin >> x;
            X ^= x;
        } else {
            int l, r;
            cin >> l >> r;
            int lo = INT_MAX, hi = INT_MIN;
            int a = l + n, b = r + n + 1, k = 0;
            while (a < b) {
                if (a & 1) {
                    int id = a ^ (X >> k);
                    lo = min(lo, mn[id]);
                    hi = max(hi, mx[id]);
                    a++;
                }
                if (b & 1) {
                    --b;
                    int id = b ^ (X >> k);
                    lo = min(lo, mn[id]);
                    hi = max(hi, mx[id]);
                }
                a >>= 1;
                b >>= 1;
                k++;
            }
            cout << hi - lo + 1 << "\n";
        }
    }
    return 0;
}