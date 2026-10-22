#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".in","r",stdin); freopen(task".out","w",stdout);
#define task "measurement"

struct Data{
    int day;
    string name;
    int diff;
} a[105];

bool cmp(Data x, Data y){
    return x.day < y.day;
}

int n;

int main(){
    FAST_IO
    FILE_IO

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i].day >> a[i].name >> a[i].diff;
    }

    sort(a + 1, a + 1 + n, cmp);

    ll c1 = 7, c2 = 7, c3 = 7;
    ll best = 7;
    ll mx = 7;
    int res = 0;

    for(int i = 1; i <= n; i++){
        if(a[i].name == "Bessie") c1 += a[i].diff;
        else if(a[i].name == "Elsie") c2 += a[i].diff;
        else c3 += a[i].diff;

        ll mx = max({c1, c2, c3});
        int nbest = 0;
        if(c1 == mx) nbest |= 4;
        if(c2 == mx) nbest |= 2;
        if(c3 == mx) nbest |= 1;

        if(nbest != best){
            res++;
            best = nbest;
        }
    }

    cout << res;

    return 0;
}