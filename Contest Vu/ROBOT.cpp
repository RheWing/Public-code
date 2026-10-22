#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task "ROBOT"
#define MAXN 1000005
#define MAXM 15
#define INF 1e18

int n, m, k;
int p[MAXM * 2];
bool f[25][25];

ll get_cst(ll p1, ll p2) {
    if (p1 > p2) swap(p1, p2);
    ll d1 = p2 - p1;
    ll d2 = n - d1;
    ll max_gap = max(d1, d2);
    return (max_gap + 1) / 2; 
}

namespace SubtaskM1{
    void solve(){
        cout << get_cst(p[0], p[1]) << "\n";
    }
}

namespace SubtaskBitmask{
    ll dp[1 << 20];

    void solve(){
        int num_robots = 2 * m;
        int max_mask = 1 << num_robots;
        
        for(int mask = 0; mask < max_mask; ++mask) dp[mask] = INF;
        dp[0] = 0;

        for(int mask = 0; mask < max_mask; mask++){
            if(dp[mask] == INF) continue;

            int i = -1;
            for(int bit = 0; bit < num_robots; bit++){
                if(!((mask >> bit) & 1)){
                    i = bit;
                    break;
                }
            }

            if(i == -1) continue; 

            for(int j = i + 1; j < num_robots; j++){
                if(!((mask >> j) & 1)){
                    if(!f[i][j]){
                        ll cst = get_cst(p[i], p[j]);
                        int nw_mask = mask | (1 << i) | (1 << j);
                        dp[nw_mask] = min(dp[nw_mask], dp[mask] + cst);
                    }
                }
            }
        }

        cout << dp[max_mask - 1] << "\n";
    }
}

int main() {
    FAST_IO
    //FILE_IO

    cin >> n >> m >> k;
    for(int i = 0; i < 2 * m; i++) cin >> p[i];

    for(int i = 0; i < k; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        f[u][v] = f[v][u] = true;
    }

    if(m == 1){
        SubtaskM1::solve();
    }else{
        SubtaskBitmask::solve();
    }

    return 0;
}