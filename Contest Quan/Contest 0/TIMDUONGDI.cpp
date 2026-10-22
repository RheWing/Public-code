#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 1005;

int n;
int a[MAXN][MAXN];
int dp2[MAXN][MAXN], dp5[MAXN][MAXN];
int f2[MAXN][MAXN], f5[MAXN][MAXN];

int cnt(int num, int f){
    if(num == 0) return 1;
    int c = 0;
    while(num > 0 && num % f == 0){
        c++;
        num /= f;
    }
    return c;
}

int main(){
    FAST_IO;

    cin >> n;

    bool zero = 0;
    int zerorow =  -1, zerocol = -1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(a[i][j] == 0){
                zero = 1;
                zerorow = i;
                zerocol = j;
            }
            f2[i][j] = cnt(a[i][j], 2);
            f5[i][j] = cnt(a[i][j], 5);
        }
    }

    dp2[1][1] = f2[1][1];
    dp5[1][1] = f5[1][1];

    for(int i = 2; i <= n; i++){
        dp2[1][i] = dp2[1][i - 1] + f2[1][i];
        dp5[1][i] = dp5[1][i - 1] + f5[1][i];
    }

    for(int i = 2; i <= n; i++){
        dp2[i][1] = dp2[i - 1][1] + f2[i][1];
        dp5[i][1] = dp5[i - 1][1] + f5[i][1];
    }

    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= n; j++){
            dp2[i][j] = f2[i][j] + min(dp2[i - 1][j], dp2[i][j - 1]);
            dp5[i][j] = f5[i][j] + min(dp5[i - 1][j], dp5[i][j - 1]);
        }
    }

    int res2 = dp2[n][n];
    int res5 = dp5[n][n];
    int res = min(res2, res5);

    if(zero && res > 1) res = 1;

    cout << res << '\n';

    return 0;
}