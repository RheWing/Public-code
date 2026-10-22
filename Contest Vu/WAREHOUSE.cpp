#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 200005;
const int B = 450;

struct Data{
    int val, idx;
};

struct Query{
    int l, r, x, idx;
};

int n, q;
int res[MAXN], bit[MAXN];
Query qu[MAXN];
Data a[MAXN];

void update(int pos, int val){
    for(; pos <= n; pos += pos & (-pos)) bit[pos] += val;
}

int get(int pos){
    int res = 0;
    for(; pos >= 1; pos -= pos & (-pos)){
        res += bit[pos];
    }
    
    return res;
}

int main(){
    FAST_IO

    cin >> n >> q;

    for(int i = 1; i <= n; i++){
        cin >> a[i].val;
        a[i].idx = i;
    }
    for(int i = 1; i <= q; i++){
        int l, r, x; cin >> l >> r >> x;
        qu[i] = {l, r, x, i};
    }

    sort(a + 1, a + 1 + n, [](Data x, Data y){
        return x.val < y.val;
    });

    sort(qu + 1, qu + 1 + q, [](Query x, Query y){
        return x.x < y.x;
    });

    int p = 1;
    for(int i = 1; i <= q; i++){
        while(p <= n && a[p].val <= qu[i].x){
            update(a[p].idx, 1);
            p++;
        }

        res[qu[i].idx] = get(qu[i].r) - get(qu[i].l - 1);
    }

    for(int i = 1; i <= q; i++) cout << res[i] << '\n';

    return 0;
}