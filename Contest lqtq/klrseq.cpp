#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 3e5 + 5;
int n, k, L, R;
ll a[MAXN], pref[MAXN], gv[MAXN], gc[MAXN];

pair<ll, int> solve(ll w){
    vector<int> q(n + 1);
    int h = 0, t = 0;
    for(int i = 1; i <= n; i++){
        int j = i - L;
        if(j >= 0){
            ll kj = gv[j] - pref[j];
            while(t > h){
                int b = q[t - 1];
                ll kb = gv[b] - pref[b];
                if(kj > kb || (kj == kb && gc[j] <= gc[b])) t--;
                else break;
            }
            q[t++] = j;
        }
        while(t > h && q[h] < i - R) h++;
        gv[i] = gv[i - 1];
        gc[i] = gc[i - 1];
        if(t > h){
            int b = q[h];
            ll cand = gv[b] - pref[b] + pref[i] - w;
            int cc = gc[b] + 1;
            if(cand > gv[i] || (cand == gv[i] && cc < gc[i])){
                gv[i] = cand;
                gc[i] = cc;
            }
        }
    }
    return {gv[n], gc[n]};
}

int main(){
    FAST_IO

    cin >> n >> k >> L >> R;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }

    ll l = -1e12, r = 1e12;
    while(l <= r){
        ll mid = (l + r) / 2;
        auto val = solve(mid);
        if(val.second <= k) r = mid - 1;
        else l = mid + 1;
    }

    auto u = solve(l);
    ll res = u.first + 1LL * k * l;
    cout << res << '\n';

    return 0;
}