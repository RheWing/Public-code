#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MOD = 998244353;

int main(){
    FAST_IO

    int t; cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        int v = m + 2;
        vector<int> g(v + 1, 0), ng(v + 1, 0), p(v + 1, 0);
        g[2] = 1;
        ll res = g[v];
        for(int i = 2; i <= n; i++){
            p[0] = 0;
            for(int j = 1; j <= v; j++){
                p[j] = p[j - 1] + g[j];
                if(p[j] >= MOD) p[j] -= MOD;
            }
            for(int k = 1; k <= v; k++){
                int val = p[k] - p[k / 2];
                if(val < 0) val += MOD;
                ng[k] = val;
            }
            swap(g, ng);
            res += g[v];
        }

        cout << res % MOD << '\n';
    }

    return 0;
}