#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

struct S{
    long long a, b;
};

bool comp(S x, S y){
    if(x.a == y.a) return x.b < y.b;
    return x.a < y.a;
}

int n;

int main() {
    FAST_IO

    cin >> n;

    vector<S> segs(n);
    for (int i = 0; i < n; i++){
        cin >> segs[i].a >> segs[i].b;
    }

    sort(segs.begin(), segs.end(), comp);

    ll res = 0;
    ll cur_a = segs[0].a;
    ll cur_b = segs[0].b;

    for (int i = 1; i < n; i++){
        if(segs[i].a <= cur_b){
            cur_b = max(cur_b, segs[i].b);
        } else{
            res += (cur_b - cur_a);
            cur_a = segs[i].a;
            cur_b = segs[i].b;
        }
    }
    res += (cur_b - cur_a);

    cout << res << "\n";

    return 0;
}
