
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 25;

int n, m;
bool adj[MAXN][MAXN], vis[MAXN];
vector<int> path;

bool DFS(int u, int cnt){
    if(cnt == n) return adj[u][0];
    for(int v = 0; v < n; v++){
        if(adj[u][v] && !vis[v]){
            vis[v] = true;
            path.push_back(v);
            if(DFS(v, cnt + 1)) return true;
            path.pop_back();
            vis[v] = false;
        }
    }

    return false;
}

void solve(){
    cin >> n >> m;

    memset(adj, 0, sizeof(adj));

    vector<pair<int,int>> ed;

    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if(adj[u][v]) continue;
        adj[u][v] = adj[v][u] = true;
        ed.push_back({u, v});
    }

    m = ed.size();

    if(n <= 4){
        cout << "YES\n";
        return;
    }
    if(m > 3 * n - 6){
        cout << "NO\n";
        return;
    }

    memset(vis, 0, sizeof(vis));
    path.clear();
    vis[0] = true;
    path.push_back(0);
    if(!DFS(0, 1)){
        cout << "NO\n";
        return;
    }

    vector<int> pos(n);
    for(int i = 0; i < n; i++) pos[path[i]] = i;
    vector<pair<int,int>> ch;
    for(int i = 0; i < m; i++){
        int u = ed[i].first;
        int v = ed[i].second;
        int a = pos[u];
        int b = pos[v];
        if(a > b) swap(a, b);
        if(b - a == 1 || (a == 0 && b == n - 1)) continue;
        ch.push_back({a, b});
    }

    int k = ch.size();

    vector<int> cr(k, 0);
    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++){
            if(i == j) continue;
            int a = ch[i].first;
            int b = ch[i].second;
            int c = ch[j].first;
            int d = ch[j].second;
            if((a < c && c < b && b < d) || (c < a && a < d && d < b)){
                cr[i] |= (1 << j);
            }
        }
    }

    int full = (1 << k) - 1;
    bool ok = false;

    for(int mask = 0; mask <= full && !ok; mask++){
        bool good = true;
        for(int i = 0; i < k && good; i++){
            if(BIT(mask, i)){
                if(cr[i] & mask) good = false;
            }
            else{
                if(cr[i] & (~mask) & full) good = false;
            }
        }
        if(good) ok = true;
    }

    cout << (ok ? "YES\n" : "NO\n");
}

int main(){
    FAST_IO

    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}
