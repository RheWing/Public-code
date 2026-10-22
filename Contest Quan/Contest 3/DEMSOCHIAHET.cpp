#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXK = 25;

ll n;
int k;
ll a[MAXK];

int main(){
    FAST_IO

    cin >> n >> k;

    for(int i = 0; i < k; i++){
        cin >> a[i];
    }

    ll res = 0;
    for(int i = 1; i < (1 << k); i++){
        ll cur = 1;
        int cnte = 0;
        bool over = 0;
        for(int j = 0; j < k; j++){
            if((i >> j) & 1){
                cnte++;
                if(a[j] > n / cur){
                    over = 1;
                    break;
                }
                cur *= a[j];
            }
        }
        if(over) continue;
        ll cnt = n / cur;
        if(cnte % 2 == 1) res += cnt;
        else res -= cnt;
    }

    cout << res;

    return 0;
}