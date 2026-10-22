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

struct Query
{
    int l, r, idx;
};

int n, q;
int cur_res = 0;
int a[MAXN], f[MAXN], res[MAXN];
Query qu[MAXN];

void add(int pos){
    if(f[a[pos]] == 0) cur_res++;
    f[a[pos]]++;
}

void remove(int pos){
    f[a[pos]]--;
    if(f[a[pos]] == 0) cur_res--;
}

int main(){
    FAST_IO

    cin >> n >> q;

    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r;
        qu[i] = {l - 1, r - 1, i};
    }

    //sort(a, a + n);
    //int *aEnd = unique(a, a + n);
    //for(int i = 0; i < n; i++) a[i] = lower_bound(a, aEnd, a[i]) - aEnd;

    //vector<int> comp;
    //for(int i = 0; i < n; i++) comp.push_back(a[i]);

    //sort(ALL(comp));
    //comp.erase(unique(ALL(comp)), comp.end());

    //for(int i = 0; i < n; i++) a[i] = lower_bound(ALL(comp), a[i]) - comp.begin() + 1;

    sort(qu, qu + q, [](Query x, Query y){
        int bx = x.l / B, by = y.l / B;
        if (bx != by) return bx < by;
        return (bx & 1) ? (x.r > y.r) : (x.r < y.r);
    });

    int cur_l = 0, cur_r = -1;

    for(int i = 0; i < q; i++){
        Query Q = qu[i];
        while(cur_r < Q.r) add(++cur_r);
        while(cur_l > Q.l) add(--cur_l);
        while(cur_r > Q.r) remove(cur_r--);
        while(cur_l < Q.l) remove(cur_l++);
        res[Q.idx] = cur_res;
    }

    for(int i = 0; i < q; i++) cout << res[i] << '\n';

    return 0;
}