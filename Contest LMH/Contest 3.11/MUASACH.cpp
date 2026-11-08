#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define llll pair<ll,ll>
#define ALL(a) (a).begin(), (a).end()
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);

const int MAXN = 1e6 + 5;

int n;

struct Data{
    ll a, b, c, d;
    bool operator < (const Data& other) const{
        return d < other.d;
    }
};

Data a[MAXN];

int main(){
    FAST_IO

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i].a >> a[i].b >> a[i].c >> a[i].d;
    }

    sort(a + 1, a + n + 1);

    priority_queue<llll> q;

    ll res = 0, S = 0;

    for(int i = 1; i <= n; i++){
        res += a[i].a * a[i].b;
        S += a[i].a;
    }

    for(int i = 1; i <= n; i++){
        q.push({a[i].b - a[i].c, a[i].a});

        ll nxt;
        if(i < n) nxt = min(a[i + 1].d, S);
        else nxt = S;
        ll space = nxt - a[i].d;

        while(!q.empty() && space > 0){
            llll x = q.top();
            q.pop();

            ll t = min(space, x.se);

            res -= t * x.fi;
            space -= t;
            x.se -= t;

            if(x.se > 0){
                q.push(x);
            }
        }
    }

    //cout << res;

    return 0;
}