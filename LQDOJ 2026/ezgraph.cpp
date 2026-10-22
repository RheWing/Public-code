#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".inp","r",stdin); freopen(task".out","w",stdout);
#define task "ezgraph"

const int MAXN = 2005;
int m, n;
char a[MAXN][MAXN];
ll c[MAXN];

void cnt(){
    c[1] = 0;
    for(int i = 2; i <= 2005; i++){
        c[i] = c[i - 1] + (i - 1);
    }
}

void sub2(){
    vector<int> w;
    ll res1 = 0;
    ll res2 = 0;
    for(int j = 1; j <= n ; j++){
        cin >> a[1][j];            
        if(a[1][j] == '.'){
            res1++;
            w.push_back(j);            
        }
    }
    for(int pos : w){
        a[1][pos] = '#';
        int len = 0;
        for(int i = 1; i <= n; i++){
            if(a[1][i] == '#'){
                len++;
            }
            else{
                res2 += c[len];
                len = 0;
            }
        } 
        if(len > 0) res2 += c[len];
        a[1][pos] = '.';
    }

    cout << res1 << ' ' << res2;
}

int main(){
    FAST_IO
    FILE_IO

    cin >> m >> n;

    cnt();
    if(m == 1){
        sub2();
        return 0;
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    cout << 0 << ' ' << 0;


    return 0;
}