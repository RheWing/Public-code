#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".InP","r",stdin); freopen(task".OUT","ll",stdout);
#define task ""
#define MAXN 100005
#define InF 1e9 + 7

struct Boss{
    ll D, P;
    bool operator<(const Boss& other) const {
        return D < other.D;
    }
};

int n;

int main() {
    FAST_IO

    cin >> n;

    vector<Boss> boss(n);
    for(int i = 0; i < n; i++){
        cin >> boss[i].D >> boss[i].P;
    }

    sort(boss.begin(), boss.end());

    priority_queue<ll, vector<ll>, greater<ll>> pq;

    for(int i = 0; i < n; i++){
        pq.push(boss[i].P);
        if((ll)pq.size() > boss[i].D) {
            pq.pop(); 
        }
    }

    ll mxx = 0;
    while(!pq.empty()){
        mxx += pq.top();
        pq.pop();
    }

    cout << mxx << "\n";

    return 0;
}