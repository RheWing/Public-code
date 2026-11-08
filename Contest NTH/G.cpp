#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 2e5 + 5;

int n, m;
ll a[MAXN], b[MAXN];
int A[MAXN], B[MAXN];

bool check(ll x){
    A[0] = A[1] = 0;
    for(int i = 1; i <= n; i++){
        A[i + 1] = max(A[i], A[i - 1] + (a[i] >= x));
    }
    B[n + 1] = B[n + 2] = 0;
    for(int i = n; i >= 1; i--){
        B[i] = max(B[i + 1], B[i + 2] + (b[i] >= x));
    }
    for(int k = 0; k <= n; k++){
        int v1 = A[k + 1] + B[k + 2];
        int v2 = A[k] + B[k + 1];
        if(max(v1, v2) >= m) return 1;
    }
    return 0;
}

int main(){
    FAST_IO

    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> b[i];

        ll l = -1e9, r = 1e9;
        while(l < r){
            ll mid = l + (r - l + 1) / 2;
            if(check(mid)) l = mid;
            else r = mid - 1;
        }

        cout << l << "\n";
    }

    return 0;
}