#include<bits/stdc++.h>
#define ll long long
#define N 100005
#define task BOOKS
using namespace std;

int n, k;
ll a[N], pref[N];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("BOOKS.INP", "r", stdin);
	freopen("BOOKS.OUT", "w", stdout);

	cin >> n >> k;

	ll t = 0;
	pref[0] = 0;
	for(int i = 1; i <= n; i++){
        cin >> a[i];
        t += a[i];
        pref[i] = pref[i - 1] + a[i];
	}

	if(n <= 20 && k <= 5){
        if(k == 1){
            cout << t << '\n';
            return 0;
        }
        if(k == 2){
            vector<ll> res;
            for(int i = 1; i < n; i++){
                res.push_back(max(pref[i], t - pref[i]));
            }
            ll ans = LLONG_MAX;
            for(ll i : res){
                ans = min(ans, i);
            }
            cout << ans << '\n';
            return 0;
        }
        if(k == 3){
            vector<ll> res;
            for(int i = 1; i <= n - 2; i++){
                for(int j = i + 1; j <= n - 1; j++){
                    ll mx = max(pref[i], pref[j] - pref[i]);
                    res.push_back(max(t - pref[j], mx));
                }
            }
            ll ans = LLONG_MAX;
            for(ll i : res){
                ans = min(ans, i);
            }
            cout << ans << '\n';
            return 0;
        }
        if(k == 4){
            vector<ll> res;
            for(int i = 1; i <= n - 3; i++){
                for(int j = i + 1; j <= n - 2; j++){
                    for(int k = j + 1; k <= n - 1; k++){
                        ll mx1 = max(pref[i], pref[j] - pref[i]);
                        ll mx2 = max(pref[k] - pref[j], t - pref[k]);
                        res.push_back(max(mx1, mx2));
                    }
                }
            }
            ll ans = LLONG_MAX;
            for(ll i : res){
                ans = min(ans, i);
            }
            cout << ans << '\n';
            return 0;
        }
        if(k == 5){
            vector<ll> res;
            for(int i = 1; i <= n - 4; i++){
                for(int j = i + 1; j <= n - 3; j++){
                    for(int k = j + 1; k <= n - 2; k++){
                        for(int q = k + 1; q <= n - 1; q++){
                            ll mx1 = max(pref[i], pref[j] - pref[i]);
                            ll mx2 = max(pref[k] - pref[j], pref[q] - pref[k]);
                            ll mx3 = max(mx1, mx2);
                            res.push_back(max(mx3, t - pref[q]));
                        }
                    }
                }
            }
            ll ans = LLONG_MAX;
            for(ll i : res){
                ans = min(ans, i);
            }
            cout << ans << '\n';
            return 0;
        }
	}
	if(k == n){
        ll res = 0;
        for(int i = 1; i <= n; i++){
            res = max(res, a[i]);
        }
        cout << res << '\n';
        return 0;
	}
	if(k == 1){
        cout << t << '\n';
        return 0;
	}

	return 0;
}
