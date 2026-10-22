#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXC = 1000;
const int MAXN = 200005;

struct Seg{
    int l, r;
    int id;
};
int n, q;
int X[MAXN], Y[MAXN];
ll pref[MAXN];
ll P;
vector<Seg> ver[MAXC + 1];
vector<Seg> hor[MAXC + 1];
unordered_map<ll, ll> posver;

ll getKey(int x, int y){
    return 1LL * x * 2001 + y;
}

bool cmpSeg(Seg a, Seg b){
    return a.l < b.l;
}

ll getPos(int x, int y){
    ll key = getKey(x, y);

    if(posver.count(key)){
        return posver[key];
    }
    if(!ver[x].empty()){
        int l = 0;
        int r = (int)ver[x].size() - 1;
        int res = -1;
        while(l <= r){
            int mid = (l + r) / 2;

            if(ver[x][mid].l <= y){
                res = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        if(res != -1 && y <= ver[x][res].r){
            int id = ver[x][res].id;
            return pref[id] + abs(y - Y[id]);
        }
    }

    int l = 0;
    int r = (int)hor[y].size() - 1;
    int res = -1;

    while(l <= r){
        int mid = (l + r) / 2;
        if(hor[y][mid].l <= x){
            res = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    int id = hor[y][res].id;
    return pref[id] + abs(x - X[id]);
}

int main(){
    FAST_IO

    cin >> q >> n;

    for(int i = 1; i <= n; i++){
        cin >> X[i] >> Y[i];
    }

    pref[1] = 0;

    for(int i = 1; i <= n; i++){
        int j = (i == n ? 1 : i + 1);
        ll len = abs(X[i] - X[j]) + abs(Y[i] - Y[j]);
        if(i < n){
            pref[i + 1] = pref[i] + len;
        }
        posver[getKey(X[i], Y[i])] = pref[i];
        if(X[i] == X[j]){
            ver[X[i]].push_back({
                min(Y[i], Y[j]),
                max(Y[i], Y[j]),
                i
            });
        }
        else{
            hor[Y[i]].push_back({
                min(X[i], X[j]),
                max(X[i], X[j]),
                i
            });
        }
    }

    P = pref[n] + abs(X[n] - X[1]) + abs(Y[n] - Y[1]);

    for(int i = 0; i <= MAXC; i++){
        sort(ALL(ver[i]), cmpSeg);
        sort(ALL(hor[i]), cmpSeg);
    }

    while(q--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        ll p1 = getPos(x1, y1);
        ll p2 = getPos(x2, y2);
        ll d = abs(p1 - p2);

        cout << min(d, P - d) << '\n';
    }

    return 0;
}