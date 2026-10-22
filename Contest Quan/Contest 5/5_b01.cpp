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
    int x, y, id;
};

int n, m;
Data xy[MAXN];
int bit[MAXN];
int y[MAXN], bao[MAXN], bibao[MAXN];

int cmp(Data a, Data b){
    if(a.x == b.x) return a.y > b.y;
    return a.x < b.x;
}

void update(int id, int val){
    for(; id <= n; id += id & -id) bit[id] += val;
}

int query(int id){
    int cnt = 0;
    for(; id >= 1; id -= id & -id) cnt += bit[id];
    return cnt;
}

int main(){
    FAST_IO

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> xy[i].x >> xy[i].y;
        xy[i].id = i;
        y[i] = xy[i].y;
    }

    sort(y + 1, y + n + 1);
    m = unique(y + 1, y + n + 1) - y - 1;

    for(int i = 1; i <= n; i++){
        xy[i].y = lower_bound(y + 1, y + m + 1, xy[i].y) - y;
    }

    sort(xy + 1, xy + n + 1, cmp);

    for(int i = 1; i <= n; i++){
        if(i > 1 && xy[i].x == xy[i - 1].x && xy[i].y == xy[i - 1].y){
            bao[xy[i].id] = bao[xy[i - 1].id]; 
        }
        else{
            bao[xy[i].id] = i - 1 - query(xy[i].y - 1);
        }
        update(xy[i].y, 1);
    }

    memset(bit, 0, sizeof(bit));

    for(int i = n; i >= 1; i--){
        if(i < n && xy[i].x == xy[i + 1].x && xy[i].y == xy[i + 1].y){
            bibao[xy[i].id] = bibao[xy[i + 1].id];
        }
        else{
            bibao[xy[i].id] = query(xy[i].y);
        }
        update(xy[i].y, 1);
    }

    for(int i = 1; i <= n; i++) cout << bibao[i] << ' ';
    cout << '\n';
    for(int i = 1; i <= n; i++) cout << bao[i] << ' ';

    return 0;
}