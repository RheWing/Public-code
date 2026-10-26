#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

struct P{
    ll x, y;
};

ll C2(ll x){
    return x * (x - 1) / 2;
}

int half(P a){
    return (a.y > 0 || (a.y == 0 && a.x > 0)) ? 0 : 1;
}

bool cmp(P a, P b){
    int ha = half(a), hb = half(b);
    if(ha != hb) return ha < hb;
    return a.x * b.y - a.y * b.x > 0;
}

int main(){
    FAST_IO

    int n;
    cin >> n;

    vector<P> p(n);
    for(auto &a : p) cin >> a.x >> a.y;

    ll total = 0;

    for(int i = 0; i < n; i++){
        vector<P> v;

        for(int j = 0; j < n; j++){
            if(j != i){
                v.push_back({p[j].x - p[i].x, p[j].y - p[i].y});
            }
        }

        sort(v.begin(), v.end(), cmp);

        int m = v.size();
        int b = 1;

        for(int a = 0; a < m; a++){
            if(b < a + 1) b = a + 1;

            while(b < a + m && v[a].x * v[b % m].y - v[a].y * v[b % m].x > 0){
                b++;
            }

            ll L = b - a - 1;
            ll R = m - 1 - L;

            total += C2(L) * C2(R);
        }
    }

    cout << total / 2 << "\n";

    return 0;
}
