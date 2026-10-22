#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIt(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FASt_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUt","w",stdout);
#define task ""

int main(){
    FASt_IO

    int t;
    cin >> t;
    while(t--){
        int n, d;
        cin >> n >> d;

        vector<ll> h(n + 1);
        h[0] = 0;
        for(int i = 1; i <= n; i++) cin >> h[i];

        vector<ll> A, B;
        for(int i = 1; i <= n; i++){
            if(h[i - 1] < h[i]){
                A.push_back(h[i - 1]);
                B.push_back(h[i]);
            }
        }

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        for(int j = 0; j < d; j++){
            ll T;
            cin >> T;
            int cntA = upper_bound(A.begin(), A.end(), T) - A.begin();
            int cntB = upper_bound(B.begin(), B.end(), T) - B.begin();
            cout << cntA - cntB << (j + 1 < d ? ' ' : '\n');
        }
    }
    return 0;
}