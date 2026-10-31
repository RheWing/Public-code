#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 200005;
const ll INF = 1e18;

struct Data{
    ll d;
    int v, s;

    bool operator > (const Data& other) const{
        return d > other.d;
    }
};

int n, m, p, k;
ll f;
vector<pair<int, ll>> adj[MAXN];
vector<int> src[MAXN];

priority_queue<Data, vector<Data>, greater<Data>> pq;

int main(){
    FAST_IO

    cin >> n >> m >> p >> f >> k;

    FOR(i, 1, m){
        int u, v;
        ll w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    FOR(i, 1, p){
        pq.push({0, i, i});
    }

    while(!pq.empty()){
        Data cur = pq.top();
        pq.pop();

        ll d = cur.d;
        int v = cur.v;
        int s = cur.s;

        if(d > f) break;
        if((int)src[v].size() >= k) continue;

        bool check = false;
        for(int x : src[v]){
            if(x == s){
                check = true;
                break;
            }
        }

        if(check) continue;

        src[v].push_back(s);

        for(pair<int, ll> e : adj[v]){
            int to = e.first;
            ll w = e.second;

            if(d + w <= f && (int)src[to].size() < k){
                pq.push({d + w, to, s});
            }
        }
    }

    vector<int> res;

    FOR(v, p + 1, n){
        if((int)src[v].size() >= k){
            res.push_back(v);
        }
    }

    cout << res.size() << "\n";

    for(int x : res){
        cout << x << " ";
    }

    cout << "\n";

    return 0;
}