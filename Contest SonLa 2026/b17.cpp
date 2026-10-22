#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);

const int MAXN = 16;

int n, m;
ll v;
ll a[MAXN][MAXN];
vector<pair<ll, int>> r;
ll col[MAXN];

int main(){
    FAST_IO

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    cin >> v;

    int L = m / 2;
    int R = m - L;
    for(int maskR = 0; maskR < (1 << n); maskR++){
        for(int j = 0; j < m; j++){
            col[j] = 0;
        }

        for(int i = 0; i < n; i++){
            if(BIT(maskR, i)){
                for(int j = 0; j < m; j++){
                    col[j] += a[i][j];
                }
            }
        }

        r.clear();
        for(int mask = 0; mask < (1 << R); mask++){
            ll sum = 0;

            for(int j = 0; j < R; j++){
                if(BIT(mask, j)){
                    sum += col[L + j];
                }
            }

            r.push_back({sum, mask});
        }

        sort(ALL(r));
        int resmaskC = -1;
        for(int mask = 0; mask < (1 << L); mask++){
            ll sumL = 0;
            for(int j = 0; j < L; j++){
                if(BIT(mask, j)){
                    sumL += col[j];
                }
            }

            ll need = v - sumL;
            int pos = lower_bound(ALL(r), make_pair(need, -1)) - r.begin();

            if(pos < (int)r.size() && r[pos].first == need){
                resmaskC = mask | (r[pos].second << L);
                break;
            }
        }

        if(resmaskC == -1){
            continue;
        }

        vector<pair<int, int>> res;

        for(int i = 0; i < n; i++){
            if(!BIT(maskR, i)){
                res.push_back({1, i + 1});
            }
        }

        for(int j = 0; j < m; j++){
            if(!BIT(resmaskC, j)){
                res.push_back({2, j + 1});
            }
        }

        cout << res.size() << '\n';
        for(auto p : res){
            cout << p.first << ' ' << p.second << '\n';
        }

        return 0;
    }

    cout << -1;

    return 0;
}