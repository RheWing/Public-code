#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

int main(){
    FAST_IO

    int t;
    cin >> t;

    while(t--){
        int n; cin >> n;
        vector<int> a(n), prv(n), nxt(n);

        for(int i = 0; i < n; i++) cin >> a[i];

        vector<int> last(n + 1, -1);
        for(int i = 0; i < n; i++){
            prv[i] = last[a[i]];
            last[a[i]] = i;
        }
        fill(ALL(last), n);
        for(int i = n - 1; i >= 0; i--){
            nxt[i] = last[a[i]];
            last[a[i]] = i;
        }

        bool ok = 1;
        vector<pair<int,int>> st;
        st.push_back({0, n - 1});
        while(!st.empty() && ok){
            auto [l, r] = st.back();
            st.pop_back();
            if(l >= r) continue;
            int p = -1;
            for(int i = 0; l + i <= r - i; i++){
                int x = l + i;
                if(prv[x] < l && nxt[x] > r){
                    p = x;
                    break;
                }
                int y = r - i;
                if(prv[y] < l && nxt[y] > r){
                    p = y;
                    break;
                }
            }
            if(p == -1){
                ok = 0;
                break;
            }
            st.push_back({l, p - 1});
            st.push_back({p + 1, r});
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}