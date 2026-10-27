#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP", "r", stdin); freopen(task".OUT", "w", stdout);
#define task ""

const int MAXN = 100005;
const int MAXK = 10001;

int n, k, u, v, e;
int h[MAXN], nx[MAXN * 2], to[MAXN * 2];
int p[MAXN], dp[MAXN], sz[MAXN];
int st[MAXN], cs[MAXN], ch[MAXN];
bool ok[MAXN];
bitset<MAXK> g[MAXK];

void dfs(int u, int f){
    p[u] = f;
    sz[u] = 1;

    for(int i = h[u]; i; i = nx[i]){
        int v = to[i];
        if(v == f) continue;

        dp[v] = dp[u] + 1;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

void go(int l, int r, int lv);

void visit(int v, int lv){
    int t = k - 1 - dp[v];

    if(t >= 0 && g[lv][t]) ok[v] = 1;

    if(st[v] < st[v + 1]) go(st[v], st[v + 1] - 1, lv);
}

void go(int l, int r, int lv){
    if(l == r){
        visit(ch[l], lv);
        return;
    }

    int m = (l + r) / 2;

    g[lv + 1] = g[lv];
    for(int i = m + 1; i <= r; i++){
        g[lv + 1] |= g[lv + 1] << sz[ch[i]];
    }
    go(l, m, lv + 1);

    g[lv + 1] = g[lv];
    for(int i = l; i <= m; i++){
        g[lv + 1] |= g[lv + 1] << sz[ch[i]];
    }
    go(m + 1, r, lv + 1);
}

int main(){
    FAST_IO

    if(fopen(task".INP", "r")){
        FILE_IO
    }

    cin >> n >> k;

    for(int i = 1; i < n; i++){
        cin >> u >> v;

        to[++e] = v;
        nx[e] = h[u];
        h[u] = e;

        to[++e] = u;
        nx[e] = h[v];
        h[v] = e;
    }

    dfs(1, 0);

    for(int i = 2; i <= n; i++) cs[p[i]]++;

    st[1] = 1;
    for(int i = 1; i <= n; i++) st[i + 1] = st[i] + cs[i];
    for(int i = 1; i <= n; i++) cs[i] = st[i];

    for(int i = 2; i <= n; i++) ch[cs[p[i]]++] = i;

    g[0][0] = 1;
    visit(1, 0);

    for(int i = 1; i <= n; i++){
        if(ok[i]) cout << i << ' ';
    }

    return 0;
}