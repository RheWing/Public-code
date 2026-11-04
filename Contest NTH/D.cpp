#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);

const int MAXN = 200005;

int n;
string s;
ll k, p[MAXN];
char d[MAXN];
vector<ll> a[2];
map<ll, ll> cnt;

int main() {
    FAST_IO

    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        cnt[p[i]]++;
    }

    cin >> s;
    for(int i = 1; i <= n; i++){
        d[i] = s[i - 1];
    }

    ll res = 0;

    for(auto x : cnt) {
        res += x.second * (x.second - 1) / 2;
    }

    for(int i = 1; i <= n; i++) {
        if(d[i] == 'L') {
            a[p[i] % 2].push_back(p[i]);
        }
    }

    sort(a[0].begin(), a[0].end());
    sort(a[1].begin(), a[1].end());

    for(int i = 1; i <= n; i++) {
        if(d[i] == 'R') {
            int t = p[i] % 2;

            ll l = p[i] + 1;
            ll r = p[i] + 2 * k;

            int x = lower_bound(a[t].begin(), a[t].end(), l) - a[t].begin();
            int y = upper_bound(a[t].begin(), a[t].end(), r) - a[t].begin();

            res += y - x;
        }
    }

    cout << res;

    return 0;
}