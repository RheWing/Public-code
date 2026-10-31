#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 200005;
const ll MOD = 998244353;

int n, par[MAXN], carry[MAXN];
vector<int> g[MAXN];
string x, y;

int main(){
    FAST_IO

    int t;
    cin >> t;

    while(t--){
        cin >> n;

        for(int i = 1; i <= n; i++){
            g[i].clear();
            par[i] = 0;
            carry[i] = 0;
        }

        for(int i = 1; i < n; i++){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        cin >> x >> y;

        vector<int> cur, nxt;
        cur.push_back(1);

        bool ok = true;
        ll res = 0, pw = 1;

        while(!cur.empty() && ok){
            int kd = -1;

            for(int v : cur){
                int dv = (x[v - 1] - '0') ^ (y[v - 1] - '0');
                int b = dv ^ carry[v];

                if(kd == -1) kd = b;
                else if(kd != b){
                    ok = false;
                    break;
                }
            }

            if(!ok) break;

            if(kd) res = (res + pw) % MOD;
            pw = pw * 2 % MOD;

            nxt.clear();

            for(int v : cur){
                int xv = x[v - 1] - '0';
                int c = (kd + xv + carry[v]) >= 2;

                for(int u : g[v]){
                    if(u == par[v]) continue;

                    par[u] = v;
                    carry[u] = c;
                    nxt.push_back(u);
                }
            }

            cur.swap(nxt);
        }

        if(!ok) cout << -1 << '\n';
        else cout << res << '\n';
    }

    return 0;
}