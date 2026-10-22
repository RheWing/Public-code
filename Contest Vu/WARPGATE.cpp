#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
const int MAXN = 100005;
const int LOG = 18;

struct Edge{
    int to, w, id;
};

struct Query{
    int u, v;
    int dis, lca;
};

int n, m;
vector<Edge> adj[MAXN];
Query q[MAXN];
int eu[MAXN], ev[MAXN], ew[MAXN];

namespace Sub12{
    int dist[2005][2005];
    void dfs(int root, int u, int p, int cur){
        dist[root][u] = cur;
        for(auto &e : adj[u]){
            if(e.to != p){
                dfs(root, e.to, u, cur + e.w);
            }
        }
    }
    void solve(){
        for(int i = 1; i <= n; i++){
            dfs(i, i, 0, 0);
        }
        int res = 2e9;
        for(int i = 1; i < n; i++){
            int u = eu[i];
            int v = ev[i];
            int w = ew[i];
            int mx = 0;
            for(int j = 1; j <= m; j++){
                int s = q[j].u;
                int t = q[j].v;
                int cur = dist[s][t];
                if(dist[s][u] + w + dist[v][t] == cur || dist[s][v] + w + dist[u][t] == cur){
                    mx = max(mx, cur - w);
                }
                else{
                    mx = max(mx, cur);
                }
            }
            res = min(res, mx);
        }
        cout << res << '\n';
    }
}

namespace Sub3{
    int pref[MAXN];
    void solve(){
        for(int i = 1; i < n; i++){
            pref[i + 1] = pref[i] + ew[i];
        }
        int mx = 0;
        for(int i = 1; i <= m; i++){
            q[i].dis = abs(pref[q[i].u] - pref[q[i].v]);
            mx = max(mx, q[i].dis);
        }
        auto check = [&](int lim){
            int cnt = 0;
            int need = 0;
            int L = 1;
            int R = n;
            for(int i = 1; i <= m; i++){
                if(q[i].dis > lim){
                    cnt++;
                    need = max(need, q[i].dis - lim);
                    int u = min(q[i].u, q[i].v);
                    int v = max(q[i].u, q[i].v);
                    L = max(L, u);
                    R = min(R, v);
                }
            }
            if(cnt == 0){
                return true;
            }
            if(L >= R){
                return false;
            }
            for(int i = L; i < R; i++){
                if(ew[i] >= need){
                    return true;
                }
            }
            return false;
        };
        int l = 0;
        int r = mx;
        int res = mx;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(check(mid)){
                res = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        cout << res << '\n';
    }
}

namespace Sub4{
    int dep[MAXN];
    int dis[MAXN];
    int up[MAXN][LOG];
    int par_w[MAXN];
    int diff[MAXN];
    int cnt;
    int need;
    bool ok;
    void dfs_init(int u, int p, int d, int w){
        dep[u] = d;
        dis[u] = w;
        up[u][0] = p;
        for(int i = 1; i < LOG; i++){
            up[u][i] = up[up[u][i - 1]][i - 1];
        }
        for(auto &e : adj[u]){
            if(e.to != p){
                par_w[e.to] = e.w;
                dfs_init(e.to, u, d + 1, w + e.w);
            }
        }
    }
    int get_lca(int u, int v){
        if(dep[u] < dep[v]){
            swap(u, v);
        }
        for(int i = LOG - 1; i >= 0; i--){
            if(dep[u] - (1 << i) >= dep[v]){
                u = up[u][i];
            }
        }
        if(u == v){
            return u;
        }
        for(int i = LOG - 1; i >= 0; i--){
            if(up[u][i] != up[v][i]){
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }
    int dfs(int u, int p){
        int sum = diff[u];
        for(auto &e : adj[u]){
            if(e.to != p){
                sum += dfs(e.to, u);
            }
        }
        if(u != 1 && sum == cnt && par_w[u] >= need){
            ok = true;
        }
        return sum;
    }
    bool check(int lim){
        cnt = 0;
        need = 0;
        fill(diff + 1, diff + n + 1, 0);
        for(int i = 1; i <= m; i++){
            if(q[i].dis > lim){
                cnt++;
                need = max(need, q[i].dis - lim);
                diff[q[i].u]++;
                diff[q[i].v]++;
                diff[q[i].lca] -= 2;
            }
        }
        if(cnt == 0){
            return true;
        }
        ok = false;
        dfs(1, 0);
        return ok;
    }
    void solve(){
        dfs_init(1, 0, 0, 0);
        int mx = 0;
        for(int i = 1; i <= m; i++){
            q[i].lca = get_lca(q[i].u, q[i].v);
            q[i].dis = dis[q[i].u] + dis[q[i].v] - 2 * dis[q[i].lca];
            mx = max(mx, q[i].dis);
        }
        int l = 0;
        int r = mx;
        int res = mx;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(check(mid)){
                res = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        cout << res << '\n';
    }
}

int main(){
    FAST_IO

    cin >> n >> m;

    bool line = true;
    for(int i = 1; i < n; i++){
        cin >> eu[i] >> ev[i] >> ew[i];
        adj[eu[i]].push_back({ev[i], ew[i], i});
        adj[ev[i]].push_back({eu[i], ew[i], i});
        if(ev[i] != eu[i] + 1){
            line = false;
        }
    }
    for(int i = 1; i <= m; i++){
        cin >> q[i].u >> q[i].v;
    }

    if(n <= 2000 && m <= 2000){
        Sub12::solve();
    }
    else if(line){
        Sub3::solve();
    }
    else{
        Sub4::solve();
    }

    return 0;
}
