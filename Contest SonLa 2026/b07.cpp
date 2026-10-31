#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 1005;
int n, m;
vector<pair<ll, int>> a;
int cnt[MAXN];

int main(){
    FAST_IO

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1;  j <= m; j++){
            int val; cin >> val;
            a.push_back({val, i});
        }
    }    

    sort(ALL(a));

    int cover = 0;
    ll res = LLONG_MAX;
    int l = 0;

    for(int r = 0; r < a.size(); r++){
        if(cnt[a[r].second]++ == 0) cover++;
        while(cover == n){
            res = min(res, a[r].first - a[l].first);
            if(--cnt[a[l].second] == 0) cover--;
            l++;
        }
    }

    cout << res;
    return 0;
}