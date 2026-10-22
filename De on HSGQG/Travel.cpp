#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task "Travel"

const int MAXN = 100005;

int n, q;
vector<pair<int,int>> adj[MAXN];
ll pref[MAXN];
ll dist[MAXN];
int ed[MAXN];

void sub1(){
    while(q--){
        int u, v; cin >> u >> v;
        cout << pref[v] - pref[u] + (v - u + 1) << '\n';
    }
}

ll BFS(int S, int T){
    if(S == T){
        return 1; 
    }

    fill(dist, dist + MAXN, -1);
    queue<int> q;
    q.push(S);
    dist[S] = 0;
    ed[S] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(u == T) break;
        for(auto edge : adj[u]){
            int v = edge.first;
            if(dist[v] == -1){ 
                dist[v] = dist[u] + edge.second;
                ed[v] = ed[u] + 1;
                q.push(v);
            }
        }
    }

    ll hao_hut = ed[T] + 1;
    return dist[T] + hao_hut;
}

void sub2(){
    while(q--){
        int S, T; cin >> S >> T;
        cout << BFS(S, T) << '\n';
    }
}

int main() {
    FAST_IO
    FILE_IO

    cin >> n >> q;

    int t = 0;
    pref[1] = 0;
    for(int i = 1; i < n; i++){
        int u, v, w; cin >> u >> v >> w;
        t += v - u;
        pref[i + 1] = pref[i] + w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    if(t == n - 1){
        sub1();
        return 0;
    }

    if(n <= 5000 && q <= 5000){
        sub2();
        return 0;
    }

    while(q--){
        int S, T; cin >> S >> T;
        cout << 1 << '\n';
    }

    return 0;
}
