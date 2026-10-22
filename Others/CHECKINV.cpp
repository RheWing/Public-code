#include<bits/stdc++.h>
#define ll long long
#define N 50005
#define task CHECKINV
using namespace std;

int n, q;
ll a[N];

namespace sub12{
    int b[10005][10005];
    bool check(int n, int q){
        if(n <= 10000 && q <= 1000) return true;
        return false;
    }
    void solve(){
        for(int i = 1; i <= n; i++){
            for(int j = i; j <= n; j++){
                if(i == j) b[i][j] = 0;
                if(a[i] > a[j]) b[i][j] = b[i][j - 1] + 1;
                else b[i][j] = b[i][j - 1];
            }
        }

        while(q--){
            int l, r; cin >> l >> r;
            ll res = 0;
            for(int i = l; i <= r; i++){
                res += b[i][r];
            }

            cout << res << '\n';
        }
    }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("CHECKINV.INP", "r", stdin);
	freopen("CHECKINV.OUT", "w", stdout);

	cin >> n >> q;

	for(int i = 1; i <= n; i++) cin >> a[i];

    if(sub12::check(n, q)) return sub12::solve(), 0;

    while(q--){
        int l, r; cin >> l >> r;

        if(l == r) cout << 0 << '\n';
        else if(l == r - 1){
            if(a[l] > a[r]) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
    }

	return 0;
}
