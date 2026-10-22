#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 4005;

int n;
int a[MAXN];
int dp[MAXN][MAXN];
int lastpos[MAXN];
vector<int> val;

int getid(int x){
    return lower_bound(ALL(val), x) - val.begin() + 1;
}

void comp(){
    for(int i = 1; i <= n; i++){
        val.push_back(a[i]);
    }

    sort(ALL(val));
    val.erase(unique(ALL(val)), val.end());
}

int main(){
    FAST_IO;

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    comp();

    int res = min(n, 2);

    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            dp[i][j] = 2;

            int need = 2 * a[i] - a[j];
            int id = getid(need);

            if(id < 1 || id > (int)val.size()) continue;
            if(val[id - 1] != need) continue;
            if(lastpos[id] == 0) continue;

            dp[i][j] = max(dp[i][j], dp[lastpos[id]][i] + 1);
            res = max(res, dp[i][j]);
        }

        lastpos[getid(a[i])] = i;
    }

    cout << res;

    return 0;
}