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

struct P{
    ll x, y;
};

int n;
ll a[MAXN], b[MAXN], S[MAXN];
P p[MAXN], tmp[MAXN];

bool cmpX(P a, P b){
    if(a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

bool cmpY(P a, P b){
    if(a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}

ll dist(P a, P b){
    ll dx = a.x - b.x;
    ll dy = a.y - b.y;
    return dx * dx + dy * dy;
}

ll solve(int l, int r){
    if(r - l <= 3){
        ll res = LLONG_MAX;

        for(int i = l; i <= r; i++){
            for(int j = i + 1; j <= r; j++){
                res = min(res, dist(p[i], p[j]));
            }
        }

        sort(p + l, p + r + 1, cmpY);
        return res;
    }

    int mid = (l + r) / 2;
    ll midX = p[mid].x;

    ll res = min(solve(l, mid), solve(mid + 1, r));

    int i = l, j = mid + 1, k = l;

    while(i <= mid && j <= r){
        if(cmpY(p[i], p[j])) tmp[k++] = p[i++];
        else tmp[k++] = p[j++];
    }

    while(i <= mid) tmp[k++] = p[i++];
    while(j <= r) tmp[k++] = p[j++];

    for(int i = l; i <= r; i++) p[i] = tmp[i];

    k = 0;

    for(int i = l; i <= r; i++){
        ll dx = p[i].x - midX;

        if(dx * dx < res) tmp[k++] = p[i];
    }

    for(int i = 0; i < k; i++){
        for(int j = i + 1; j < k && j <= i + 7; j++){
            res = min(res, dist(tmp[i], tmp[j]));
        }
    }

    return res;
}

int main(){
    FAST_IO

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        S[i] = S[i - 1] + a[i];
    }

    for(int i = 1; i <= n; i++) cin >> b[i];

    for(int i = 1; i <= n; i++){
        p[i - 1] = {b[i], S[i]};
    }

    sort(p, p + n, cmpX);

    cout << solve(0, n - 1) << '\n';

    return 0;
}