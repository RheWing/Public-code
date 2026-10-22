
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

int n, p[MAXN], par[MAXN];
int tin[MAXN], tout[MAXN], t = 0;
int bit[MAXN], res[MAXN];
vector<int> adj[MAXN];
int st[MAXN], top = 0;

void add(int i, int v){
    for(; i <= n; i += i & -i) bit[i] += v;
}

int query(int i){
    int res = 0;
    for(; i > 0; i -= i & -i) res += bit[i];
    return res;
}

int main(){
    FAST_IO

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> p[i];

    for(int i = 2; i <= n; i++){
        cin >> par[i];
        adj[par[i]].push_back(i);
    }

    st[++top] = 1;

    while(top){
        int u = st[top--];
        if(u > 0){
            tin[u] = ++t;
            st[++top] = -u;
            for(int i = (int)adj[u].size() - 1; i >= 0; i--){
                st[++top] = adj[u][i];
            }
        }else{
            u = -u;
            tout[u] = t;
        }
    }

    vector<int> ord(n);
    for(int i = 0; i < n; i++) ord[i] = i + 1;

    sort(ALL(ord), [&](int u, int v){
        return p[u] > p[v];
    });

    for(int u : ord){
        res[u] = query(tout[u]) - query(tin[u] - 1);
        add(tin[u], 1);
    }

    for(int i = 1; i <= n; i++){
        cout << res[i] << '\n';
    }

    return 0;
}
