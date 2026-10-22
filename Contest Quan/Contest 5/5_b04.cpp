#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 300005;

int n, m;
int bit[MAXN], last[MAXN];

void update(int id, int val){
    for(; id <= n; id += id & -id) bit[id] += val;
}

ll query(int id){
    ll res = 0;
    for(; id >= 1; id -= id & -id) res += bit[id];
    return res; 
}

int main(){
    FAST_IO

    cin >> n >> m;

    ll res = 1LL * n * (m - 1);

    for(int i = 1; i <= n; i++){
        int a; cin >> a;
        if(last[a]){
            int p = last[a];
            int d = query(i - 1) - query(p);
            res -= 1LL * (m - 1) - d;
            update(p, -1);
        }
        update(i, 1);
        last[a] = i;
    }

    cout << res;
    
    return 0;
}