#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);

const int MAXN = 50005;

int n, m;
vector<int> adj[MAXN];
int d[MAXN];
int dist[MAXN];

void bfs(int s){
    fill(dist + 1, dist + n + 1, -1);
    queue<int> q;
    q.push(s);
    dist[s] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : adj[u]){
            if(dist[v] != -1) continue;
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
}

bool check(int s){
    bfs(s);
    for(int i = 1; i <= n; i++){
        if(d[i] != -1 && dist[i] != d[i]){
            return false;
        }
    }

    return true;
}

int main(){
    FAST_IO

    cin >> n >> m;

    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; i++) cin >> d[i];

    int root = -1;

    for(int i = 1; i <= n; i++){
        if(d[i] != -1){
            root = i;
            break;
        }
    }

    vector<int> res;

    if(root == -1){
        for(int i = 1; i <= n; i++){
            res.push_back(i);
        }
    } else{
        bfs(root);
        vector<int> cand;

        for(int i = 1; i <= n; i++){
            if(dist[i] == d[root]){
                cand.push_back(i);
            }
        }

        for(int s : cand){
            if(check(s)){
                res.push_back(s);
            }
        }
    }

    cout << res.size() << '\n';

    for(int x : res){
        cout << x << ' ';
    }

    return 0;
}