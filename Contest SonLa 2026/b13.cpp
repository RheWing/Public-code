#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);

const int MAXN = 200005;

int n;
ll m;
string s;
ll a[MAXN];

int main(){
    FAST_IO;

    cin >> n >> m;
    cin >> s;

    ll t = 0;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        t += a[i];
    }

    bool same = true;

    for(int i = 1; i < n; i++){
        if(s[i] != s[0]){
            same = false;
            break;
        }
    }

    if(same){
        cout << t;
        return 0;
    }

    ll lost = 0;

    for(int i = 0; i < n; i++){
        int nxt = (i + 1) % n;
        if(s[i] == 'R' && s[nxt] == 'L'){
            ll ls = 0;
            int j = (i - 1 + n) % n;
            while(s[j] == 'R'){
                ls += a[j + 1];
                j = (j - 1 + n) % n;
            }
            lost += min(m, ls);
            ll rs = 0;
            j = (i + 2) % n;
            while(s[j] == 'L'){
                rs += a[j + 1];
                j = (j + 1) % n;
            }
            lost += min(m, rs);
        }
    }

    cout << t - lost;

    return 0;
}