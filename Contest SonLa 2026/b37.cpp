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
const int MAXA = 1000005;
int n;
int a[MAXN], spf[MAXA + 5];
int omega[MAXN];

void sieve(){
    for(int i = 2; i <= MAXA; i++) spf[i] = i;
    for(int i = 2; i * i <= MAXA; i++){
        if(spf[i] == i){
            for(int j = i * i; j <= MAXA; j += i){
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
}

void OMG(){
    for(int i = 1; i <= n; i++){
        while(a[i] > 1){
            omega[i]++;
            a[i] /= spf[a[i]];
        }
    }
}

int main(){
    FAST_IO

    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];

    sieve();
    OMG();

    for(int i = 1; i <= n; i++){
        if(omega[i] % 2 == 0) cout << 2 << ' ';
        else cout << 1 << ' ';
    }

    return 0;
}