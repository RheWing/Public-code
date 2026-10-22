#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 500005;

string s;
int a[MAXN];

int main(){
    FAST_IO

    cin >> s;

    int n = s.length();
    a[0] = n;

    for(int i = 1, l = 0, r = 0; i < n; i++){
        if(i <= r){
            a[i] = min(r - i + 1, a[i - l]);
        }
        while(i + a[i] < n && s[a[i]] == s[a[i] + i]) a[i]++;
        if(a[i] + i - 1 > r){
            l = i;
            r = i + a[i] - 1;
        }
    }

    for(int i = 0; i < n; i++) cout << a[i] << ' ';

    return 0;
}