#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".in","r",stdin); freopen(task".out","w",stdout);
#define task "cowsignal"

int m, n, k;

char a[105][105];

int main(){
    FAST_IO
    FILE_IO

    cin >> m >> n >> k;

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= m; i++){
        for(int r = 1; r <= k; r++){
            for(int j = 1; j <= n; j++){
                string s = "";
                for(int l = 1; l <= k; l++){
                    s += a[i][j];
                }
                cout << s;
            }
            cout << '\n';
        }
    }

    return 0;
}