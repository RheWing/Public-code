
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

struct Data{
    int x, y, id;
};

int n, k;
Data a[MAXN], b[MAXN];
int bit[MAXN], pos[MAXN];
ll res = 0;
int cnt = 0;

vector<int> ys;
set<pair<int,int>> acty;

bool cmp(Data a, Data b){
    return a.x < b.x;
}

void update(int id, int val){
    for(; id <= n; id += id & -id) bit[id] += val;
}

int query(int id){
    int res = 0;
    for(; id >= 1; id -= id & -id) res += bit[id];
    return res;
}

int main(){
    FAST_IO

    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        cin >> a[i].x >> a[i].y;
        a[i].id = i;
        b[i] = a[i];
        ys.push_back(a[i].y);
    }

    sort(ALL(ys));
    ys.erase(unique(ALL(ys)), ys.end());

    for(int i = 1; i <= n; i++){
        pos[i] = lower_bound(ALL(ys), a[i].y) - ys.begin() + 1;
    }

    sort(a + 1, a + n + 1, cmp);

    int l = 1;
    for(int i = 1; i <= n; i++){
        while(l < i && a[i].x - a[l].x >= k){
            update(pos[a[l].id], -1);
            acty.erase({a[l].y, a[l].id});
            l++;
        }

        int low = lower_bound(ALL(ys), a[i].y - k + 1) - ys.begin() + 1;
        int high = upper_bound(ALL(ys), a[i].y + k - 1) - ys.begin();
        int cur = query(high) - query(low - 1);

        if(cur > 0){
            cnt += cur;

            if(cnt > 1){
                cout << -1;
                return 0;
            }

            auto it = acty.lower_bound({a[i].y - k + 1, 0});
            int j = it->second;

            res = 1LL * (k - abs(a[i].x - b[j].x)) * (k - abs(a[i].y - b[j].y));
        }

        update(pos[a[i].id], 1);
        acty.insert({a[i].y, a[i].id});
    }

    cout << res;
    return 0;
}
