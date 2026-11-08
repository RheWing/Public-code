#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int N = 2e5 + 5;
int n, y;
vector<pair<ll, int>> a;

int main(){
    FAST_IO

    cin >> n >> y;
    for(int i = 1; i <= n; i++){
        ll h, l, r;
        cin >> h >> l >> r;
        a.push_back({h + y * l, +1});
        a.push_back({h + y * r + 1, -1});
    }
    sort(ALL(a));

    int cur = 0, best = 0;
    ll cnt = 0;

    int i = 0;
    while(i < a.size()){
        ll x = a[i].first;
        while(i < a.size() && a[i].first == x){
            cur += a[i].second;
            i++;
        }
        if(i == a.size()) break;
        ll len = a[i].first - x;
        if(cur > best){
            best = cur;
            cnt = len;
        } else if(cur == best){
            cnt += len;
        }
    }

    cout << best << ' ' << cnt << '\n';

    return 0;
}