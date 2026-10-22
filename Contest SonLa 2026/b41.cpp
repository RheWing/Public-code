#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

struct Data{
    int u, v;
    ll w;
    bool operator<(const Data& other) const{
        return w < other.w;
    }
};

struct DSU{
    vector<int> par;
    vector<ll> sz;
    DSU(int n){
        par.resize(n + 1);
        sz.resize(n + 1, 1);
        for(int i = 1; i <= n; i++) par[i] = i;
    }

    int find(int v){
        if(v == par[v]) return v;
        return par[v] = find(par[v]);
    }

    ll uni(int a, int b){
        a = find(a);
        b = find(b);
        if(a != b){
            ll p = sz[a] * sz[b];
        }
    }
};

int n;


int main(){
    FAST_IO

    return 0;
}