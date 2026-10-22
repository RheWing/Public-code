#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 100005;
const int B = 320;

ll a[MAXN];
ll lazy[MAXN];
ll sum[MAXN];

int n, q;

void update(int l, int r, ll v){
    int bl = l / B;
    int br = r / B;

    if(bl == br){
        for(int i = l; i <= r; i++){
            a[i] += v;
            sum[bl] += v;
        }
        return;
    }

    int endL = (bl + 1) * B - 1;
    for(int i = l; i <= endL; i++){
        a[i] += v;
        sum[bl] += v;
    }

    int startR = br * B;
    for(int i = startR; i <= r; i++){
        a[i] += v;
        sum[br] += v;
    }

    for(int b = bl + 1; b < br; b++){ 
        int l = b * B;
        int r = min(n, (b + 1) * B - 1);
        int cnt = r - l + 1;
        sum[b] += v * cnt;
        lazy[b] += v;
    }
}

ll query(int l, int r){
    int bl = l / B;
    int br = r / B;

    ll res = 0;
    if(bl == br){
        for(int i = l; i <= r; i++){
            res += a[i] + lazy[bl];
        }
        return res;
    }

    int endL = (bl + 1) * B - 1;
    for(int i = l; i <= endL; i++){
        res += a[i] + lazy[bl];
    }

    int startR = br * B;
    for(int i = startR; i <= r; i++){
        res += a[i] + lazy[br];
    }

    for(int b = bl + 1; b < br; b++){ 
        res += sum[b];
    }

    return res;
}

int main(){
    FAST_IO

    cin >> n >> q;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum[i / B] += a[i];
    }

    while(q--){
        int t;
        cin >> t;

        if(t == 1){
            int l, r;
            ll v;
            cin >> l >> r >> v;

            update(l, r, v);
        }
        else{
            int l, r;
            cin >> l >> r;

            cout << query(l, r) << '\n';
        }
    }

    return 0;
}