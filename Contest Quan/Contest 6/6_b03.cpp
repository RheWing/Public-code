
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

struct P{
    ll x, y;
};

ll cross(P o, P a, P b){
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

bool cmp(P a, P b){
    return a.x != b.x ? a.x < b.x : a.y < b.y;
}

bool cmp2(P a, P b){
    return a.x == b.x && a.y == b.y;
}

vector<P> convexhull(vector<P> p){
    sort(ALL(p), cmp);
    p.erase(unique(ALL(p), cmp2), p.end());

    int n = p.size();
    if(n <= 2) return p;

    vector<P> h(2 * n);
    int k = 0;

    for(int i = 0; i < n; i++){
        while(k >= 2 && cross(h[k - 2], h[k - 1], p[i]) <= 0) k--;
        h[k++] = p[i];
    }

    for(int i = n - 2, t = k + 1; i >= 0; i--){
        while(k >= t && cross(h[k - 2], h[k - 1], p[i]) <= 0) k--;
        h[k++] = p[i];
    }

    h.resize(k - 1);
    return h;
}

int main(){
    FAST_IO

    int n;
    cin >> n;

    vector<P> p(n);
    for(auto &a : p) cin >> a.x >> a.y;

    vector<P> h = convexhull(p);
    int m = h.size();

    long double per = 0, area2 = 0;

    for(int i = 0; i < m; i++){
        P a = h[i], b = h[(i + 1) % m];
        long double dx = (long double)a.x - b.x;
        long double dy = (long double)a.y - b.y;
        per += sqrtl(dx * dx + dy * dy);
    }

    for(int i = 1; i + 1 < m; i++){
        area2 += cross(h[0], h[i], h[i + 1]);
    }

    cout << fixed << setprecision(6);
    cout << per << "\n" << area2 / 2 << "\n";

    return 0;
}
