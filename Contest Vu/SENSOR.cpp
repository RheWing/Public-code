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

int n, q;
ll a[MAXN];
ll Block[500];

int main() {
    FAST_IO

    cin >> n >> q;

    int B = sqrt(n);

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        Block[i / B] += a[i];
    }

    while(q--){
        int t;
        cin >> t;

        if(t == 1){
            int p;
            ll x;
            cin >> p >> x;

            Block[p / B] += x - a[p];
            a[p] = x;
        }
        else{
            int l, r;
            cin >> l >> r;

            ll res = 0;
            int blockL = l / B;
            int blockR = r / B;

            if(blockL == blockR){
                for(int i = l; i <= r; i++){
                    res += a[i];
                }
            }
            else{
                int endL = (blockL + 1) * B - 1;

                for(int i = l; i <= min(r, endL); i++) res += a[i];

                for(int b = blockL + 1; b < blockR; b++) res += Block[b];

                for(int i = blockR * B; i <= r; i++) res += a[i];
            }

            cout << res << '\n';
        }
    }

    return 0;
}

