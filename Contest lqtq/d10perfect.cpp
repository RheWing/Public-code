#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define ll long long 
using namespace std;

const int MAXN = 2005;
bitset<MAXN> adj[MAXN];
int n, m;

int main(){
    FAST_IO

    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        if(u == v) continue;
        adj[u].set(v);
        adj[v].set(u);
    }

    if(n < 6 || m < 9){
        cout << "NO";
        return 0;
    }

    for(int u = 1; u <= n; u++){
        for(int v = u + 1; v <= n; v++){
            bitset<MAXN> nei = adj[u] & adj[v];
            if(nei.count() < 3) continue;

            for(int w = v + 1; w <= n; w++){
                if((adj[w] & nei).count() >= 3){
                    cout << "YES";
                    return 0;
                }
            }
        }
    }

    cout << "NO";
    return 0;
}