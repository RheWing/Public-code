#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);

const int MAXN = 3005;

string a, b;
int L[MAXN][MAXN];
int na[MAXN][10], nb[MAXN][10];
char res[MAXN];

int main(){
    FAST_IO

    cin >> a;
    cin >> b;
    int n = a.length(), m = b.length();

    for(int i = n - 1; i >= 0; i--){
        for(int j = m - 1; j >= 0; j--){
            if(a[i] == b[j]) L[i][j] = L[i + 1][j + 1] + 1;
            else L[i][j] = max(L[i + 1][j], L[i][j + 1]);
        }
    }

    for(int i = 0; i < 10; i++){
        na[n][i] = n;
        nb[m][i] = m;
    }

    for(int i = n - 1; i >= 0; i--){
        for(int d = 0; d < 10; d++) na[i][d] = na[i + 1][d];
        na[i][a[i] - '0'] = i;
    }
    for(int i = m - 1; i >= 0; i--){
        for(int d = 0; d < 10; d++) nb[i][d] = nb[i + 1][d];
        nb[i][b[i] - '0'] = i;
    }

    int best = 0;
    for(int i = 1; i <= 9; i++){
        int pa = na[0][i], pb = nb[0][i];
        if(pa < n && pb < m){
            best = max(best, L[pa][pb]);
        }
    }

    if(best == 0){
        cout << 0 << '\n';
        return 0;
    }

    int len = 0, i = 0, j = 0, rem = best;
    bool fi = 1;
    while(rem > 0){
        for(int d = 9; d >= (fi ? 1 : 0); d--){
            int pa = na[i][d], pb = nb[j][d];
            if(pa < n && pb < m && 1 + L[pa + 1][pb + 1] >= rem){
                res[len++] = '0' + d;
                i = pa + 1;
                j = pb + 1;
                rem--;
                break;
            }
        }
        fi = 0;
    }

    for(int i = 0; i < len; i++) cout << res[i];

    return 0;
}