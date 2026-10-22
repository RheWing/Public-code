#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".inp","r",stdin); freopen(task".out","w",stdout);
#define task ""
#define MAXN 300005

int n, m;

struct Fenwick{
    int n;
    int bit[MAXN];

    void init(int s){
        n = s;
        for(int i = 1; i <= n; i++) bit[i] = 0;
    }

    void add(int i, int x){
        for(; i <= n; i += i & -i){
            bit[i] += x;
        }
    }

    int sum(int i){
        int res = 0;
        for(; i > 0; i -= i & -i){
            res += bit[i];
        }

        return res;
    }
};

int main() {
    FAST_IO
    
    cin >> n >> m;

    Fenwick bitL, bitR;
    bitL.init(n + 5);
    bitR.init(n + 5);

    while(m--){
        int q, l, r;
        cin >> q >> l >> r;

        if(q == 1){
            bitL.add(l, 1);
            bitR.add(r, 1);
        }
        else{
            cout << bitL.sum(r) - bitR.sum(l - 1) << '\n';
        }
    }

    return 0;
}
