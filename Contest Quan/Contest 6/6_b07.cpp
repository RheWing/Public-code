#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 200005;

int n;
vector<int> g[MAXN];
int d[MAXN];

void bfs(int s){
    fill(d + 1, d + n + 1, -1);
    queue<int> q;
    q.push(s);
    d[s] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v : g[u]){
            if(d[v] == -1){
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}

int main(){
    FAST_IO

    cin >> n;

    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bfs(1);
    int A = 1;

    for(int i = 2; i <= n; i++){
        if(d[i] > d[A]) A = i;
    }

    bfs(A);
    int B = 1;

    for(int i = 2; i <= n; i++){
        if(d[i] > d[B]) B = i;
    }

    int dA[MAXN];
    for(int i = 1; i <= n; i++) dA[i] = d[i];

    bfs(B);

    for(int i = 1; i <= n; i++){
        cout << max(dA[i], d[i]) << " ";
    }

    cout << "\n";

    return 0;
}
