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
int n, k;
int a[MAXN], org[MAXN];

int main(){
    FAST_IO

    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        org[i] = a[i];
    }

    for(int i = 1; i <= n - 1; i++){
        a[i + 1] = max(a[i + 1], a[i] - k);
    }
    for(int i = n - 1; i >= 1; i--){
        a[i] = max(a[i], a[i + 1] - k);
    }

    ll res = 0;
    for(int i = 1; i <= n; i++){
        res += abs(a[i] - org[i]);
    }

    cout << res << '\n';

    return 0;
}