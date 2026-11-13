#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

int main() {
    FAST_IO

    int q;
    cin >> q;

    while (q--) {
        int t;
        cin >> t;
        
        if (t == 1) {
            ull x, y;
            cin >> x >> y;
            cout << (x & y) << "\n";
        } 
        else if (t == 2) {
            ull x, y;
            cin >> x >> y;
            cout << (x | y) << "\n";
        } 
        else if (t == 3) {
            ull x, y;
            cin >> x >> y;
            cout << (x ^ y) << "\n";
        } 
        else if (t == 4) {
            ull x;
            int y;
            cin >> x >> y;
            cout << (x << y) << "\n";
        } 
        else if (t == 5) {
            ull x;
            int y;
            cin >> x >> y;
            cout << (x >> y) << "\n";
        } 
        else if (t == 6) {
            ull x;
            int y;
            cin >> x >> y;
            cout << ((x >> y) & 1ULL) << "\n";
        } 
        else if (t == 7) {
            ull x;
            int i;
            ull v;
            cin >> x >> i >> v;
            ull res = (x & ~(1ULL << i)) | (v << i);
            cout << res << "\n";
        }
    }

    return 0;
}
