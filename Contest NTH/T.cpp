#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);

const int MAXN = 5e5 + 5;
int n, m;
vector<int> G[MAXN];
int comp_g[MAXN];
bool vis_g[MAXN];
vector<set<int>> unvis_sets;

void bfs_org(int st, int comp_id, vector<int>& ver){
    queue<int> q;
    q.push(st);
    vis_g[st] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        comp_g[u] = comp_id;
        ver.push_back(u);
        for(int v : G[u]){
            if(!vis_g[v]){
                vis_g[v] = true;
                q.push(v);
            }
        }
    }
}

int bfs_inter(int st, int comp_id){
    queue<int> q;
    q.push(st);
    unvis_sets[comp_id].erase(st);
    int sz = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        sz++;
        auto it = unvis_sets[comp_id].begin();
        while(it != unvis_sets[comp_id].end()){
            int v = *it;
            if(!binary_search(G[u].begin(), G[u].end(), v)){
                q.push(v);
                it = unvis_sets[comp_id].erase(it);
            }
            else{
                it++;
            }
        }
    }
    return sz;
}

int main(){
    FAST_IO

    cin >> n >> m;

    FOR(i, 1, m){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    FOR(i, 1, n) sort(G[i].begin(), G[i].end());

    int num_comp_g = 0;
    vector<vector<int>> g_comp_v;
    FOR(i, 1, n){
        if(!vis_g[i]){
            num_comp_g++;
            vector<int> v;
            bfs_org(i, num_comp_g, v);
            g_comp_v.push_back(v);
        }
    }

    unvis_sets.resize(num_comp_g + 1);
    FOR(id, 1, num_comp_g){
        for(int v : g_comp_v[id - 1]){
            unvis_sets[id].insert(v);
        }
    }

    vector<int> cm_comp_sizes;
    FOR(id, 1, num_comp_g){
        for(int v : g_comp_v[id - 1]){
            if(unvis_sets[id].count(v)){
                int sz = bfs_inter(v, id);
                cm_comp_sizes.push_back(sz);
            }
        }
    }

    sort(cm_comp_sizes.begin(), cm_comp_sizes.end());

    ll res = 0;
    for(int sz : cm_comp_sizes){
        res += 1LL * sz * (sz - 1) / 2;
    }

    cout << res << '\n';

    return 0;
}