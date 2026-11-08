#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 305;
const int NEG = -1e9;

int n, m, k;
int a[MAXN][MAXN], f[MAXN][MAXN], g[MAXN][MAXN];
ll m1[2 * MAXN], m2[2 * MAXN];

int main(){
    FAST_IO

    cin >> m >> n >> k;

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= k; i++){
        int x, u, y, v;
        cin >> x >> u >> y >> v;
        for(int i = x; i <= u; i++){
            for(int j = y; j <= v; j++){
                if(i == x && j == y){
                    f[i][j] = a[i][j];
                    continue;
                }
                int best = NEG;
                if(i > x) best = max(best, f[i - 1][j]);
                if(j > y) best = max(best, f[i][j - 1]);
                f[i][j] = a[i][j] + best;
            }
        }
        for(int i = u; i >= x; i--){
            for(int j = v; j >= y; j--){
                if(i == u && j == v){
                    g[i][j] = a[i][j];
                    continue;
                }
                int best = NEG;
                if(i < u) best = max(best, g[i + 1][j]);
                if(j < v) best = max(best, g[i][j + 1]);
                g[i][j] = a[i][j] + best;
            }
        }

        int sl = x + y + 1, sr = u + v - 1;
        for(int i = sl; i <= sr; i++){
            m1[i] = m2[i] = NEG;
        }
        for(int i = x; i <= u; i++){
            for(int j = y; j <= v; j++){
                int s = i + j;
                if(s <= x + y || s >= u + v) continue;
                ll t = f[i][j] + g[i][j] - a[i][j];
                if(t > m1[s]){
                    m2[s] = m1[s];
                    m1[s] = t;
                }
                else if(t > m2[s]){
                    m2[s] = t;
                } 
            }
        }

        ll res = LLONG_MAX;
        for(int s = sl; s <= sr; s++){
            res = min(res, m2[s]);
        }

        cout << res << '\n';
    }

    return 0;
}