#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 105;

int n, m;
vector<string> black(MAXN), white(MAXN);

int main(){
    FAST_IO

    cin >> n >> m;

    for(int i = 1; i <= n; i++) cin >> black[i];
    for(int i = 1; i <= n; i++) cin >> white[i];

    int res = 0;

    for(int j = 0; j < m; j++){
        bool has_black[256] = {0};
        for(int i = 1; i <= n; i++){
            has_black[(char)black[i][j]] = 1;
        }
        bool dif = 1;
        for(int i = 1; i <= n; i++){
            if(has_black[(char)white[i][j]]){
                dif = 0;
                break;
            }
        }
        if(dif) res++;
    }

    cout << res;

    return 0;
}