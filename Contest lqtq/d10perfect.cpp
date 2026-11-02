#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""


int n, m;

int main() {
    FAST_IO

    cin >> n >> m;
    
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        adj[u][v] = adj[v][u] = 1;
    }

    if(n < 6 || m < 9){
        cout << "NO";
        return 0;
    }

    for(int u = 1; u <= n; u++){
        for(int v = u + 1; v <= n; v++){
            vector<int> nei;
            vector<bool> f(n + 1, 0);
            for(int x = 1; x <= n; x++){
                if(x != u && x != v && adj[u][x] && adj[v][x]){
                    nei.push_back(x);
                    f[x] = 1;
                }
                if(nei.size() < 3) continue;
                for(int w = 1; w <= n; w++){
                    if(w == u || w == v || f[w]) continue;
                    int cnt = 0;
                    for(int x : nei){
                        if(adj[w][x] && ++cnt == 3){
                            cout << "YES";
                            return 0;
                        }
                    }
                }
            }
        }
    }

    cout << "NO";

    return 0;
}
