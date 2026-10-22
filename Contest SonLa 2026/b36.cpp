#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 300005;

int n;
int a[MAXN];
int incr[MAXN], decr[MAXN];

int main(){
    FAST_IO

    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++){
        incr[i] = 1;
        decr[i] = 1;
    }

    for(int i = 2; i <= n; i++){
        if(a[i] > a[i - 1]){
            incr[i] = incr[i - 1] + 1;
        }
    }

    for(int i = n - 1; i >= 1; i--){
        if(a[i] > a[i + 1]){
            decr[i] = decr[i + 1] + 1;
        }
    }

    ll res = 0;
    for(int i = 1; i <= n; i++){
        res += 1LL * incr[i] * decr[i];
    }

    cout << res;

    return 0;
}