#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 300005;
const int INF = 1e9;

int n, m;
vector<pair<int, char>> adj[MAXN];
int d[MAXN];
bool vis[MAXN];
queue<int> q;

int main(){
    FAST_IO

    cin >> n >> m;

    for(int i = 1; i <= m; i++){
        int u, v;
        char a;
        cin >> u >> v >> a;
        adj[u].push_back({v, a});
        adj[v].push_back({u, a});
    }

    fill(d + 1, d + n + 1, INF);
    d[n] = 0;
    q.push(n);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto e : adj[u]){
            int v = e.first;
            if(d[v] == INF){
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }

    if(d[1] == INF){
        cout << -1 << '\n';
        return 0;
    }

    string res = "";
    vector<int> cur = {1};
    vis[1] = true;

    int step = d[1];
    for(int s = 0; s < step; s++){
        char mn = 'z' + 1;
        for(int u : cur){
            for(auto e : adj[u]){
                int v = e.first;
                if(d[u] == d[v] + 1){
                    if(e.second < mn){
                        mn = e.second;
                    }
                }
            }
        }
        res += mn;

        vector<int> nxt;
        for(int u : cur){
            for(auto e : adj[u]){
                int v = e.first;
                if(d[u] == d[v] + 1 && e.second == mn){
                    if(!vis[v]){
                        vis[v] = 1;
                        nxt.push_back(v);
                    }
                }
            }
        }

        cur.swap(nxt); 
        nxt.clear();

    }

    cout << res << '\n';

    return 0;
}