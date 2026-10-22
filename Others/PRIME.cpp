#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task "PRIME"
#define MAXN 1000005

int t;
vector<int> p;
bool a[MAXN + 5];

void Sang(){
    for(int i = 0; i <= MAXN; i++) a[i] = 1;
    a[0] = a[1] = 0;

    for(int i = 2; i * i <= MAXN; i++){
        if(a[i]){
            for(int j = i * i; j <= MAXN; j += i) a[j] = 0;
        }
    }

    for(int i = 2; i <= MAXN; i++) if(a[i]) p.push_back(i);
}

bool Prime(ll n){
    if( n < 2) return 0;

    for(int z : p){
        if(1LL * z * z > n) break;
        if(n % z == 0) return 0;
    }

    return 1;
}

int main(){
    FAST_IO
    FILE_IO

    Sang();

    cin >> t;
    while(t--){
        ll n; cin >> n;

        if(n < 2){
            cout << 2 << '\n';
            continue;
        }

        n++;
        if(n % 2 == 0) n++;

        while(!Prime(n)) n += 2;

        cout << n << '\n';
    }

    return 0;
}