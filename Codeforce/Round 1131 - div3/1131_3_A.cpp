#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

int main() {
    int t;
    cin >> t;
    while(t--){
        int n, m;
        string p, q;
        cin >> n >> m >> p >> q;

        int cnt[26] = {0};
        for (char c : p) cnt[c - 'a']++;
        for (char c : q) cnt[c - 'a']--;

        int tar[26] = {0};
        tar['s' - 'a'] = 1;
        tar['i' - 'a'] = 1;
        tar['x' - 'a'] = 1;

        bool ok = true;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] != tar[i]) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}