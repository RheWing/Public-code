
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

bool cmpx(P a, P b){
    return a.x != b.x ? a.x < b.x : a.y < b.y;
}

bool cmpy(P a, P b){
    return a.x == b.x && a.y == b.y;
}

P o;
ll cross(P o, P a, P b){
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

bool cmpangle(P a, P b){
    return cross(o, a, b) > 0;
}

vector<P> convexhull(vector<P> p){
    sort(ALL(p), cmpx);
    p.erase(unique(ALL(p), cmpy), p.end());

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

    int s = 0;
    for(int i = 1; i < n; i++){
        if(p[i].y < p[s].y || (p[i].y == p[s].y && p[i].x < p[s].x)){
            s = i;
        }
    }

    swap(p[0], p[s]);
    o = p[0];

    sort(p.begin() + 1, p.end(), cmpangle);

    int m = (n - 1) / 2;
    cout << o.x << " " << o.y << " " << p[1 + m].x << " " << p[1 + m].y << "\n";

    return 0;
}
