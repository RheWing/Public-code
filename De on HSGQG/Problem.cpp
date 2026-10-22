#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task "Problem"

const int MAXN = 100005;

int n;
int a[MAXN], mark[MAXN];

bool check(int x){
    if(x == 1) return 0;
    if(x == 2) return 1;
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0) return 0;
    }
    return 1;
}

int main(){
    FAST_IO
    FILE_IO

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(check(a[i])) mark[i] = 1;
    }

    ll len = 0;
    ll res = 0;
    for(int i = 1; i <= n; i++){
        if(mark[i] == 0) len++;
        else{
            res += len * (len + 1) / 2;
            len = 0; 
        }
    }
    if(len > 0) res += len * (len + 1) / 2;

    cout << res << '\n';

    return 0;
}