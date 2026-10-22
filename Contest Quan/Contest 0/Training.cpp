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

int n, q;
string s;
char c[MAXN], d[MAXN];

int S(int pos){
    for(int i = 1; i <= q; i++){
        if(s[pos - 1] == c[i]){
            if(d[i] == 'L') pos--;
            else pos++;
        }

        if(pos == 0) return -1;
        if(pos == n + 1) return 1;
    }

    return 0;
}

int main(){
    FAST_IO

    cin >> n >> q;
    cin >> s;

    for(int i = 1; i <= q; i++){
        cin >> c[i] >> d[i];
    }

    int l = 1;
    int r = n;
    int laL = 0;

    while(l <= r){
        int mid = (l + r) / 2;

        if(S(mid) == -1){
            laL = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }

    l = 1;
    r = n;
    int fR = n + 1;

    while(l <= r){
        int mid = (l + r) / 2;

        if(S(mid) == 1){
            fR = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }

    cout << max(0, fR - laL - 1) << '\n';

    return 0;
}