#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 100005;

int n, m, q;
vector<int> adj[MAXN];
vector<int> HeAdj[MAXN];

ll val[MAXN];
ll sumHe[MAXN];
bool He[MAXN];

int main(){
    FAST_IO

    cin >> n >> m >> q;

    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int B = sqrt(m) + 1;

    for(int i = 1; i <= n; i++){
        if((int)adj[i].size() >= B){
            He[i] = true;

            for(int v : adj[i]){
                HeAdj[v].push_back(i);
            }
        }
    }

    while(q--){
        int t;
        cin >> t;

        if(t == 1){
            int u;
            ll v;

            cin >> u >> v;

            val[u] += v;

            for(int h : HeAdj[u]){
                sumHe[h] += v;
            }
        }
        else{
            int u;
            cin >> u;

            if(He[u]){
                cout << sumHe[u] << '\n';
            }
            else{
                ll res = 0;

                for(int v : adj[u]){
                    res += val[v];
                }

                cout << res << '\n';
            }
        }
    }

    return 0;
}