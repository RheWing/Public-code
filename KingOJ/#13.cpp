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
const ll MAXA = 1000000;

int n;
ll a[MAXN];
int prime[MAXA + 1];

void sieve(){
    for(int i = 1; i <= MAXA; i++) prime[i] = 1;
    prime[1] = 0;
    for(int i = 2; i * i <= MAXA; i++){ 
        if(prime[i]){
            for(int j = i * i; j <= MAXA; j += i){
                prime[j] = 0;
            }
        }
    }
}

int main(){
    FAST_IO;

    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];

    sieve();

    for(int i = 1; i <= n; i++){
        if(a[i] < 4) cout << "NO\n";
        else{
            ll root = round(sqrt(a[i]));
            if(root * root == a[i] && root <= MAXA && prime[root]) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}
