#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXA = 500005;

ll cnt[MAXA];
ll preCnt[MAXA];
ll preSum[MAXA];

int main(){
    FAST_IO

    int n;
    cin >> n;

    int mx = 0;

    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        cnt[x]++;
        mx = max(mx, x);
    }

    for(int i = 1; i <= mx; i++){
        preCnt[i] = preCnt[i - 1] + cnt[i];
        preSum[i] = preSum[i - 1] + 1LL * i * cnt[i];
    }

    for(int k = 2; k <= n; k++){
        ll res = 0;
        for(int r = k; r <= mx + k; r += k){
            int L = r - k + 1;
            int R = min(r, mx);
            if(L > R) continue;
            ll C = preCnt[R] - preCnt[L - 1];
            ll S = preSum[R] - preSum[L - 1];
            res += 1LL * r * C - S;
        }

        cout << res << '\n';
    }

    return 0;
}