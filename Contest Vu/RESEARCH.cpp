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


struct Query{
    int l, r, x, idx;
};

int n, q;
int a[MAXN], cnt[MAXN], f[MAXN], res[MAXN];
Query qu[MAXN];

void add(int pos){
    int x = a[pos];
    f[cnt[x]]--;
    cnt[x]++;
    f[cnt[x]]++;
}

void remove(int pos){
    int x = a[pos];
    f[cnt[x]]--;
    cnt[x]--;
    f[cnt[x]]++;
}

int main(){
    FAST_IO

    cin >> n >> q;

    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= q; i++){
        int l, r, x; cin >> l >> r >> x;
        qu[i] = {l, r, x, i};
    }

    sort(qu + 1, qu + 1 + q, [](Query x, Query y){
        int bx = x.l / B, by = y.l / B;
        if(bx != by) return bx < by;
        return (bx & 1) ? (x.r > y.r) : (x.r < y.r);
    });

    int cur_l = 1, cur_r = 0;
    for(int i = 1; i <= q; i++){
        Query Q = qu[i];
        while(cur_r < Q.r) add(++cur_r);
        while(cur_l > Q.l) add(--cur_l);
        while(cur_r > Q.r) remove(cur_r--);
        while(cur_l < Q.l) remove(cur_l++);

        res[Q.idx] = f[Q.x];
    }

    for(int i = 1; i <= q; i++) cout << res[i] << '\n';

    return 0;
}