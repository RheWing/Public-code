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

struct G{
    int L, R, q;
};

vector<G> gs;
vector<array<int, 3>> op;
int n;
int a[MAXN], b[MAXN], p[MAXN];

int main(){
    FAST_IO

    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];

    int j = 1;
    for(int i = 1; i <= n; i++){
        while(j <= n && a[j] != b[i]) j++;
        if(j > n){
            cout << -1 << '\n';
            return 0;
        }
        p[i] = j;
    }

    for(int i = 1; i <= n;){
        int k = i;
        while(k + 1 <= n && p[k + 1] == p[i]) k++;
        gs.push_back({i, k, p[i]});
        i = k + 1;
    }

    for(auto g : gs) if(g.q > g.R) op.push_back({2, g.L, g.q});

    for(int i = gs.size() - 1; i >= 0; i--) if(gs[i].q < gs[i].L) op.push_back({1, gs[i].q, gs[i].R});

    for(auto g : gs){
        if(g.L <= g.q && g.q <= g.R){
            if(g.L < g.q) op.push_back({2, g.L, g.q});
            if(g.q < g.R) op.push_back({1, g.q, g.R});
        }
    }

    cout << op.size() << '\n';
    for(auto o : op) cout << o[0] << ' ' << o[1] << ' ' << o[2] << '\n';

    return 0;
}