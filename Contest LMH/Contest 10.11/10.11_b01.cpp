#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);

const int MAXN = 1e5 + 5;

int n;
int a[MAXN];
vector<pair<int,ll>> cur;

int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a % b);
}

int main(){
    FAST_IO

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    ll res = 0;
    for(int i = 1; i <= n; i++){
        vector<pair<int,ll>> nxt;
        nxt.push_back({a[i], 1LL});
        for(auto j : cur){
            int ngcd = gcd(j.first, a[i]);
            nxt.push_back({ngcd, j.second});
        }
        sort(ALL(nxt));
        vector<pair<int,ll>> comb;
        for(auto j : nxt){
            if(!comb.empty() && comb.back().first >= j.first){
                comb.back().second += j.second;
            }
            else{
                comb.push_back(j);
            }
        }
        cur = comb;
        comb.clear();
        for(auto j : cur){
            if(j.first == 1) res += j.second;
        }
    }

    cout << res << '\n';

    return 0;
}