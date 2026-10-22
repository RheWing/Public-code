#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 100005;
const int B = 320;

int n, q;
ll a[MAXN], lazy[350];
vector<ll> vec[350];

void rebuild(int id){
    vec[id].clear();

    int l = id * B + 1;
    int r = min(n, (id + 1) * B);

    for(int i = l; i <= r; i++){
        vec[id].push_back(a[i]);
    }

    sort(ALL(vec[id]));
}

void update(int l, int r, int val){
    int bl = (l - 1) / B;
    int br = (r - 1) / B;

    if(bl == br){
        for(int i = l; i <= r; i++){
            a[i] += val;
        }
        rebuild(bl);
        return;
    }

    int endl = min(n, (bl + 1) * B);
    for(int i = l; i <= endl; i++){
        a[i] += val;
    }
    rebuild(bl);

    int startr = br * B + 1;
    for(int i = startr; i <= r; i++){
        a[i] += val;
    }
    rebuild(br);

    for(int b = bl + 1; b <= br - 1; b++){
        lazy[b] += val;
    }
}

ll query(int l, int r, ll x){
    int bl = (l - 1) / B;
    int br = (r - 1) / B;

    ll res = 0;

    if(br == bl){
        for(int i = l; i <= r; i++){
            if(a[i] + lazy[i] <= x) res++;
        }

        return res;
    }

    int endl = min(n, (bl + 1) * B);

    for(int i = l; i <= endl; i++){
        if(a[i] + lazy[bl] <= x) res++;
    }
    
    int startr = br * B + 1;

    for(int i = startr; i <= r; i++){
        if(a[i] + lazy[br] <= x) res++;
    }

    for(int b = bl + 1; b <= br - 1; b++){
        ll need = x - lazy[b];
        res += upper_bound(vec[b].begin(), vec[b].end(), need) - vec[b].begin();
    }

    return res;
}

int main(){
    FAST_IO

    cin >> n >> q;

    for(int i = 1; i <= n; i++) cin >> a[i];

    int numb = (n - 1) / B;

    for(int b = 0; b <= numb; b++){
        rebuild(b);
    }

    while(q--){
        int t; cin >> t;
        if(t == 1){
            int l, r;
            ll x;
            cin >> l >> r >> x;
            update(l, r, x);
        }
        else{
            int l, r;
            ll x;
            cin >> l >> r >> x;

            cout << query(l, r, x) << '\n';
        }
    }

    return 0;
}