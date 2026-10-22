#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);

const int MAXN = 100005;
int n;
int a[MAXN];

int main(){
    FAST_IO

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    ll res = abs(a[1]);
    for(int i = 2; i <= n; i++) res += abs(a[i] - 2 * a[i - 1] + a[i - 2]);

    cout << res;
    
    return 0;
}