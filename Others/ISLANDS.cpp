#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".inp","r",stdin); freopen(task".out","w",stdout);
#define task ""
#define MAXN 100005

int n, q;
int res[MAXN], cnt[MAXN];
vector<pair<int,int>> a;

int main() {
    FAST_IO
    //FILE_IO

    cin >> n >> q;

    for(int i = 1; i <= n; i++){
        int c; cin >> c;
        for(int j = 1; j <= c; j++){
            int v; cin >> v;
            a.push_back({v, i});
        }
    }
    
    vector<pair<int,int>> qq(q);
    for(int i = 0; i < q; i++){
        cin >> qq[i].first;
        qq[i].second = i;
    }

    sort(ALL(a), greater<pair<int,int>>());
    sort(ALL(qq), greater<pair<int,int>>());

    int run = 0;
    int best = 0;
    int id = n;
    for(int i = 0; i < q; i++){
        int A = qq[i].first;
        while(run < a.size() && a[run].first >= A){
            int x = a[run].second;
            cnt[x]++;
            if(cnt[x] > best || (cnt[x] == best && x > id)){
                best = cnt[x];
                id = x;
            }
            run++;
        }
        res[qq[i].second] = id;
    }

    for(int i = 0; i < q; i++){
        cout << res[i] << '\n';
    }

    return 0;
}
