#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);

const int MAXN = 100005;

int n;
int last[MAXN];
bool ok[MAXN];

int main(){
    FAST_IO

    int T;
    cin >> T;

    while(T--){
        cin >> n;

        for(int i = 1; i <= n; i++){
            last[i] = 0;
            ok[i] = false;
        }

        for(int i = 1; i <= n; i++){
            int x;
            cin >> x;
            if(last[x] != 0 && i - last[x] <= 2){
                ok[x] = true;
            }

            last[x] = i;
        }

        bool found = false;

        for(int x = 1; x <= n; x++){
            if(ok[x]){
                if(found) cout << ' ';
                cout << x;
                found = true;
            }
        }

        if(!found) cout << -1;

        cout << '\n';
    }

    return 0;
}