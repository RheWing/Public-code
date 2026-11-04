#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const double EPS = 1e-8;
const int MAXN = 2005;

struct P{
    double x, y;
    bool operator<(const P& o) const {
        if(abs(x - o.x) > EPS) return x < o.x;
        return y < o.y - EPS; 
    }
    bool operator==(const P& o) const {
        return abs(x - o.x) <= EPS && abs(y - o.y) <= EPS;
    }
};

struct Circle{
    double x, y, r, c;
};

vector<P> get(const Circle& c1, const Circle& c2){
    double d = hypot(c1.x - c2.x, c1.y - c2.y);
    if(d > c1.r + c2.r + EPS || d < abs(c1.r - c2.r) - EPS || d < EPS) return {};
    double a = (c1.r * c1.r - c2.r * c2.r + d * d) / (2 * d);
    double h = sqrt(max(0.0, c1.r * c1.r - a * a));
    double cx = c1.x + a * (c2.x - c1.x) / d;
    double cy = c1.y + a * (c2.y - c1.y) / d;
    P p1 = {cx + h * (c1.y - c2.y) / d, cy + h * (c2.x - c1.x) / d};
    P p2 = {cx - h * (c1.y - c2.y) / d, cy - h * (c2.x - c1.x) / d};
    if(abs(h) < EPS) return {p1};
    return {p1, p2}; 
}

int par[MAXN], Rank[MAXN];

int find(int u){
    if(par[u] == u) return u;
    return par[u] = find(par[u]);
}

bool uni(int u, int v){
    int ru = find(u);
    int rv = find(v);
    if(ru != rv){
        if(Rank[ru] < Rank[rv]) par[ru] = rv;
        else if(Rank[ru] > Rank[rv]) par[rv] = ru;
        else{
            par[rv] = ru;
            Rank[ru]++;
        }
        return true;
    }
    return false;
}

int n;
Circle a[MAXN];
vector<P> point;

int main(){
    FAST_IO

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i].x >> a[i].y >> a[i].r;
        par[i] = i;
        Rank[i] = 0;
    }

    int k = 0;
    for(int i = 1; i <= n; i++){
        vector<P> pts;
        for(int j = 1; j <= n; j++){
            if(i == j) continue;
            auto v = get(a[i], a[j]);
            if(v.size()) if(uni(i, j)) k++;
            for(auto x : v){
                pts.push_back(x);
                point.push_back(x);
            }
        }
        sort(ALL(pts));
        pts.erase(unique(ALL(pts)), pts.end());
        a[i].c = pts.size();
    }
    sort(ALL(point));
    point.erase(unique(ALL(point)), point.end());

    int V = 0;
    for(int i = 1; i <= n; i++) V += a[i].c;

    cout << V - point.size() + (n - k) + 1;

    return 0;
}