#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".in","r",stdin); freopen(task".out","w",stdout);
#define task "mixmilk"

ll c[5], m[5];

int main(){
    FAST_IO
    FILE_IO

    for(int i = 0; i < 3; i++) cin >> c[i] >> m[i];

    int f = 0;
    for(int i = 1; i <= 100; i++){
        int g = (f + 1) % 3;
        if(c[g] <= m[f] + m[g]){
            m[f] = m[f] + m[g] - c[g];
            m[g] = c[g];            
        }
        else{
            m[g] += m[f];
            m[f] = 0;
        }
        f = (f + 1) % 3;
    }

    for(int i = 0; i < 3; i++) cout << m[i] << '\n';

    return 0;
}