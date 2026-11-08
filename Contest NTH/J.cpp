#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

int n, m, q;
set<int> cX, cY;
multiset<int> dX, dY;

int main(){
    FAST_IO

    cin >> n >> m >> q;

    cX.insert(0); cX.insert(n);
    cY.insert(0); cY.insert(m);
    dX.insert(n);
    dY.insert(m);

    while(q--){
        int op, k;
        cin >> op >> k;

        if(op == 1){ 
            auto it = cX.upper_bound(k);
            int r = *it;
            int l = *prev(it);
            dX.erase(dX.find(r - l));
            dX.insert(k - l);
            dX.insert(r - k);
            cX.insert(k);
        }else{
            auto it = cY.upper_bound(k);
            int r = *it;
            int l = *prev(it);
            dY.erase(dY.find(r - l));
            dY.insert(k - l);
            dY.insert(r - k);
            cY.insert(k);
        }

        ll maxrong = *dX.rbegin();
        ll maxdai = *dY.rbegin();

        cout << maxrong * maxdai << "\n";
    }

    return 0;
}
