#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 300005;

int n, m;
int par[MAXN];
int Rank[MAXN];

int find(int u){
    if(par[u] == u) return u;
    return par[u] = find(par[u]);
}

bool uni(int u, int v){
    int ru = find(u);
    int rv = find(v);
    if(ru != rv){
        if(Rank[ru] < Rank[rv]) par[ru] = rv;
        else if(Rank[ru] > Rank[rv]) par[rv] = ru;
        else{
            par[rv] = ru;
            Rank[ru]++;
        }
        return true;
    }
    return false;
}

int main(){
    FAST_IO

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        par[i] = i;
        Rank[i] = 0;
    }

    int res = 0;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        if(!uni(u, v)) res++;
        cout << res << '\n';
    }

    return 0;
}