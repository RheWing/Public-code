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

struct Data{
    int a, b;
} contest[MAXN], problem[MAXN];

bool cmp(Data x, Data y){
    return x.a < y.a;
}

int n, m;

int main(){
    FAST_IO

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        cin >> contest[i].a >> contest[i].b;
    }

    for(int i = 1; i <= m; i++){
        cin >> problem[i].a >> problem[i].b;
    }

    sort(contest + 1, contest + n + 1, cmp);
    sort(problem + 1, problem + m + 1, cmp);

    ll res = 0;
    int mx = 0;
    int p = 1;

    for(int i = 1; i <= m; i++){
        while(p <= n && contest[p].a <= problem[i].a){
            mx = max(mx, contest[p].b);
            p++;
        }

        if(mx > problem[i].b){
            res += 1LL * (mx - problem[i].b);
        }
    }

    cout << res << '\n';
    return 0;
}