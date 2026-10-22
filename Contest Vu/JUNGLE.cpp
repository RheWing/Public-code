#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
const int MAXN = 200005;

struct Creeps{
    ll x, t, v;
    ll u, w;
    int id;
} a[MAXN], b[MAXN];

int n;

namespace Subtask1{
    bool check(){
        return n <= 20;
    }
    bool cmp(Creeps A, Creeps B){
        return A.t < B.t;
    }
    void solve(){
        ll res = 0;
        for(int mask = 0; mask < (1 << n); mask++){
            int cnt = 0;
            for(int i = 0; i < n; i++){
                if(BIT(mask, i)){
                    b[++cnt] = a[i + 1];
                }
            }
            sort(b + 1, b + cnt + 1, cmp);
            bool ok = true;
            ll pos = 0;
            ll tim = 0;
            ll gold = 0;
            for(int i = 1; i <= cnt; i++){
                if(abs(b[i].x - pos) > b[i].t - tim){
                    ok = false;
                    break;
                }
                pos = b[i].x;
                tim = b[i].t;
                gold += b[i].v;
            }
            if(ok){
                res = max(res, gold);
            }
        }
        cout << res;
    }
}

namespace Subtask2{
    ll dp[MAXN];
    bool check(){
        return n <= 2000;
    }
    bool cmp(Creeps A, Creeps B){
        if(A.u != B.u) return A.u < B.u;
        return A.w < B.w;
    }
    void solve(){
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(a[i].u >= 0 && a[i].w >= 0){
                b[++cnt] = a[i];
            }
        }
        if(cnt == 0){
            cout << 0;
            return;
        }
        sort(b + 1, b + cnt + 1, cmp);
        ll res = 0;
        for(int i = 1; i <= cnt; i++){
            dp[i] = b[i].v;
            ll best = 0;
            for(int j = 1; j < i; j++){
                if(b[j].w <= b[i].w){
                    best = max(best, dp[j]);
                }
            }
            dp[i] += best;
            res = max(res, dp[i]);
        }
        cout << res;
    }
}

namespace Subtask3{
    bool check(){
        for(int i = 2; i <= n; i++){
            if(a[i].x != a[1].x){
                return false;
            }
        }
        return true;
    }
    void solve(){
        ll res = 0;
        ll need = abs(a[1].x);
        for(int i = 1; i <= n; i++){
            if(a[i].t >= need){
                res += a[i].v;
            }
        }
        cout << res;
    }
}

namespace Subtask4{
    ll bit[MAXN];
    ll val[MAXN];
    int m;
    bool cmp(Creeps A, Creeps B){
        if(A.u != B.u) return A.u < B.u;
        return A.w < B.w;
    }
    void update(int pos, ll v){
        for(int i = pos; i <= m; i += i & -i){
            bit[i] = max(bit[i], v);
        }
    }
    ll get(int pos){
        ll res = 0;
        for(int i = pos; i > 0; i -= i & -i){
            res = max(res, bit[i]);
        }
        return res;
    }
    void solve(){
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(a[i].u >= 0 && a[i].w >= 0){
                b[++cnt] = a[i];
                val[cnt] = a[i].w;
            }
        }
        if(cnt == 0){
            cout << 0;
            return;
        }
        sort(val + 1, val + cnt + 1);
        m = unique(val + 1, val + cnt + 1) - val - 1;
        sort(b + 1, b + cnt + 1, cmp);
        ll res = 0;
        for(int i = 1; i <= cnt; i++){
            int pos = lower_bound(val + 1, val + m + 1, b[i].w) - val;
            ll cur = get(pos) + b[i].v;
            res = max(res, cur);
            update(pos, cur);
        }
        cout << res;
    }
}

int main(){
    FAST_IO

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i].x >> a[i].t >> a[i].v;
        a[i].u = a[i].t - a[i].x;
        a[i].w = a[i].t + a[i].x;
        a[i].id = i;
    }

    if(Subtask1::check()){
        Subtask1::solve();
    }
    else if(Subtask3::check()){
        Subtask3::solve();
    }
    else if(Subtask2::check()){
        Subtask2::solve();
    }
    else{
        Subtask4::solve();
    }

    return 0;
}