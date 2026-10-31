#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

int main(){
    FAST_IO

    int t; cin >> t;
    while(t--){
        int n; cin >> n;

        vector<int> a(n + 1);
        bool midb = 0;
        int sum = 0;
        for(int i = 1;  i<= n; i++){
            cin >> a[i];
            sum += a[i];
        }

        for(int i = 2; i + 1 <= n; i++){
            if(a[i] >= 2) midb = 1;
        }

        bool endb = (a[n] >= 2 || a[1] >= 2);

        if(midb){
            cout << sum - 1 << '\n';
        }
        else if(endb){
            cout << sum - n + 1 << '\n';
        }
        else{
            cout << -1 << '\n';
        }
    }
    return 0;
}