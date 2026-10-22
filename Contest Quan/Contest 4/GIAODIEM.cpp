#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int OFF = 1000001;      
const int SZ = 2000005;
int bit[SZ];

void upd(int i, int v){
    for(; i < SZ; i += i & -i) bit[i] += v; 
}

int qry(int i){ 
    int s = 0; 
    for(; i > 0; i -= i & -i) s += bit[i]; 
    return s; 
}

struct Event {
    int x, t, a, b;
    bool operator<(const Event o) const{
        if (x != o.x) return x < o.x;
        return t < o.t;
    }
};

int n;
vector<Event> ev;

int main(){
    FAST_IO

    cin >> n;

    ev.reserve(2 * n);
    for(int i = 0; i < n; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 == x2){                       
            ev.push_back({x1, 1, y1 + OFF, y2 + OFF});
        } else{                            
            ev.push_back({x1, 0, y1 + OFF, 0});
            ev.push_back({x2, 2, y1 + OFF, 0});
        }
    }

    sort(ev.begin(), ev.end());
    ll ans = 0;
    for(auto e : ev) {
        if(e.t == 0) upd(e.a, 1);
        else if (e.t == 2) upd(e.a, -1);
        else ans += qry(e.b) - qry(e.a - 1);
    }

    cout << ans << "\n";

    return 0;
}