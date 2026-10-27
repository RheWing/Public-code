#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 1005;
const int INF = 1e9 + 7;

int n, m;
int mn[MAXN];

int main(){
    FAST_IO

    cin >> n >> m;

    fill(mn + 1, mn + n + 1, INF);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int x; cin >> x;
            mn[i] = min(mn[i], x);
        }
    }

    sort(mn + 1, mn + n + 1);

    cout << mn[n] - mn[1] << '\n';
    return 0;
}