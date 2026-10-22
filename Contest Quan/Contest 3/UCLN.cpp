#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 200005;

int n;
int a[MAXN];

int main() {
    FAST_IO
    
    cin >> n;
    int mxval = 0;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        mxval = max(mxval, a[i]);
    }

    vector<int> cnt(mxval + 1, 0);
    for(int x : a) cnt[x]++;

    for(int g = mxval; g >= 1; g--){
        int mul = 0;
        for(int j = g; j <= mxval; j += g){
            mul += cnt[j];
            if(mul >= 2) {
                cout << g;
                return 0; 
            }
        }
    }

    return 0;
}
