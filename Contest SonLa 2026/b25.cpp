
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);

const ll INF = LLONG_MAX;

int main() {
    FAST_IO

    int T;
    cin >> T;

    while(T--){
        int n, q;
        ll v;
        cin >> n >> q >> v;

        vector<ll> a(n + 2, 0);

        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }

        vector<int> d(n + 3, 0);
        vector<char> must(n + 2, 0), forb(n + 2, 0);

        for(int k = 0; k < q; k++){
            int l, r;
            cin >> l >> r;

            must[r] = 1;
            d[l + 1]++;
            d[r]--;
        }

        bool ok = true;
        int cur = 0;

        for(int i = 1; i <= n; i++){
            cur += d[i];
            forb[i] = (cur > 0);

            if(forb[i] && must[i]){
                ok = false;
            }
        }

        ll M = 0, cap = INF;
        int j = -1;

        for(int i = 1; i <= n && ok; i++){
            if(must[i]){
                if(a[i] == 0){
                    a[i] = M + 1;

                    if(a[i] > v){
                        ok = false;
                        break;
                    }

                    j = i;
                    cap = INF;
                } else{
                    if(a[i] <= M){
                        ok = false;
                        break;
                    }

                    cap = min(cap, a[i]);
                }

                M = a[i];
            } else if(forb[i]){
                if(a[i] == 0){
                    a[i] = 1;
                } else if(a[i] > M){
                    if(j == -1 || a[i] >= cap){
                        ok = false;
                        break;
                    }

                    a[j] = a[i];
                    M = a[i];
                }
            } else{
                if(a[i] == 0){
                    a[i] = 1;
                    j = i;
                    cap = INF;
                }

                M = max(M, a[i]);
            }
        }

        if(!ok){
            cout << -1 << '\n';
        } else{
            for(int i = 1; i <= n; i++){
                cout << a[i] << (i == n ? '\n' : ' ');
            }
        }
    }

    return 0;
}
