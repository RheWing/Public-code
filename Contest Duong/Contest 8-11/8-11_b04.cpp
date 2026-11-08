#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

int n, k;
ll m = 0;

int main(){
    FAST_IO

    cin >> n >> k;

    priority_queue<ll> pq;
    for(int i = 1; i <= n; i++){
        ll a; cin >> a;
        if(a >= 0){
            m += a;
            continue;
        }
        ll c = -a;
        if(m >= c){
            m -= c;
            pq.push(c);
        }
        else if(!pq.empty() && pq.top() > c && m + pq.top() >= c){
            ll t = pq.top();
            pq.pop();
            m += t - c;
            pq.push(c);
        }
        if(pq.size() > k){
            m += pq.top();
            pq.pop();
        }
    }
    if(pq.size() != k) cout << -1 << '\n';
    else cout << m << '\n';

    return 0;
}