#include<bits/stdc++.h>
#define ll long long
#define N 100005
#define task "CAMERA"
using namespace std;

int n;
vector<int> adj[N];
int deep[N];
int cnt[N];

void dfs(int u, int p){
    for(int v : adj[u]){
        if(v != p){
            deep[v] = deep[u] + 1;
            dfs(v, u);
        }
    }
}

namespace sub2{
    void solve(){
        int b = 0;
        if(n % 3 != 0) b = 1;
        cout << (n / 3) + b << '\n';
    }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen(task".INP", "r", stdin);
	freopen(task".OUT", "w", stdout);

    cin >> n;

    int t = 0;
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        t += abs(u - v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(t == n - 1) return sub2::solve(), 0;

    dfs(1, 0);

    int d = 0;
    for(int i = 1; i <= n; i++){
        cnt[deep[i]]++;
        d = max(d, deep[i]);
    }

    ll res = 0;
    for(int i = d - 1; i >= 0; i -= 3){
        if(cnt[i + 1] < cnt[i]) res += cnt[i - 1];
        else res += cnt[i];
    }

    cout << res << '\n';

	return 0;
}
