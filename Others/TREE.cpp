#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task "TREE"
#define MAXN 400005
#define INF 1e18

int n;
int color[MAXN];
vector<int> adj[MAXN];

namespace SubtaskN2{
    int res[MAXN];
    int vis_color[MAXN];
    int dist_cnt = 0;

    void dfs(int u, int p, int root){
        if(vis_color[color[u]] == 0) dist_cnt++;
        vis_color[color[u]]++;

        res[root] += dist_cnt;

        for(int v : adj[u]){
            if(v != p){
                dfs(v, u, root);
            }
        }

        vis_color[color[u]]--;
        if(vis_color[color[u]] == 0) dist_cnt--;
    }

    void solve(){
        for(int i = 1; i <= n; i++){
            dist_cnt = 0;
            dfs(i, 0, i);
        }

        for(int i = 1; i <= n; i++){
            cout << res[i] << (i == n ? "" : " ");
        }
        cout << "\n";
    }
}

namespace Subtask4{
    void solve(){
        for(int i = 1; i <= n; i++){
            cout << n << (i == n ? "" : " ");
        }
        cout << "\n";
    }
}

int main() {
    FAST_IO
    FILE_IO

    cin >> n;

    bool check4 = true;
    for(int i = 1; i <= n; i++){
        cin >> color[i];
        if(i > 1 && color[i] != color[1]) check4 = false;
    }

    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(check4){
        Subtask4::solve();
    }else{
        SubtaskN2::solve();
    }

    return 0;
}