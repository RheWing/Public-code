#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

int main(){
    FAST_IO

    int t; cin >> t;

    while(t--){
        int x, y, z;
        cin >> x >> y >> z;

        int n = x + y + z;

        char c;
        if(z >= x) c = 'S';
        else if(y >= z) c = 'R';
        else c = 'P';
        
        cout << string(n, c) << '\n';
    }

    return 0;
}