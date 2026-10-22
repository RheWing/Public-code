#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 200005;
int n, q;
int a[MAXN], b[MAXN], c[MAXN];

int main(){
    FAST_IO

    cin >> n >> q;

    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];

    for(int i = 1; i <= n; i++) c[i] = a[i] - b[i];

    sort(c + 1, c + 1 + n);

    while(q--){
        int x, y; cin >> x >> y;

        int pos = upper_bound(c + 1, c + 1 + n, y) - c;
        int cnt = n - pos + 1;
        if(cnt >= x) cout << 1;
        else cout << 0;
    }

    return 0;
}