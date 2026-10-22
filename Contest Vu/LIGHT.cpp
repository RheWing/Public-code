#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 200005;
const int B = 450;

ll a[MAXN];
ll lazy[MAXN];

int n, q;

void update(int l, int r, ll v){
    int bl = l / B;
    int br = r / B;

    if(bl == br){
        for(int i = l; i <= r; i++) a[i] += v;
        return;
    }

    int endL = (bl + 1) * B - 1;
    for(int i = l; i <= endL; i++) a[i] += v;

    int startR = br * B;
    for(int i = startR; i <= r; i++) a[i] += v;

    for(int b = bl + 1; b < br; b++) lazy[b] += v;
}

ll query(int p){
    return a[p] + lazy[p / B];
}

int main(){
    FAST_IO

    cin >> n >> q;

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
            int p;
            cin >> p;

            cout << query(p) << '\n';
        }
    }

    return 0;
}