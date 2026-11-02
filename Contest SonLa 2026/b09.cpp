#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 500005;

int n;
ll a[MAXN], res[MAXN];

ll cal(int t){
    ll res = 0;
    for(int i = 0; i < n; i++){
        int l = (i - t + n) % n;
        res += min(a[i], a[l]);
    }
    return res;
}

void DAC(int tmin, int tmax){
    if(tmin > tmax) return;
    int tmid = tmin + (tmax - tmin) / 2;
    res[tmid] = cal(tmid);
    DAC(tmin, tmid - 1);
    DAC(tmid + 1, tmax); 
}

int main(){
    FAST_IO

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    DAC(1, n);

    for(int i = 1; i <= n; i++){
        cout << res[i] << ' ';
    }
    cout << '\n';
    return 0;
}