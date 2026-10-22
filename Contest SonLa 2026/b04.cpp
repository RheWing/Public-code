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
    ll l, r, f;
};
struct Query{
    ll l, A;
    int id;
};
struct Event{
    ll x, f;
    int id, type;
};

struct Fenwick{
    int n;
    vector<int> bit;

    void init(int _n){
        n = _n;
        bit.assign(n + 5, 0);
    }

    void update(int pos, int val){
        for(int i = pos; i <= n; i += i & -i){
            bit[i] += val;
        }
    }

    int get(int pos){
        int res = 0;
        for(int i = pos; i > 0; i -= i & -i){
            res += bit[i];
        }

        return res;
    }
};

int n;
Data a[MAXN];
ll res[MAXN];
vector<ll> CR;
vector<ll> CD;
Fenwick bitR;
Fenwick bitD;

int getR(ll x){
    return (int)(lower_bound(ALL(CR), x) - CR.begin()) + 1;
}

int getD(ll x){
    return (int)(lower_bound(ALL(CD), x) - CD.begin()) + 1;
}

bool cmpQuery(Query a, Query b){
    return a.l < b.l;
}

bool cmpEvent(Event a, Event b){
    if(a.x != b.x){
        return a.x < b.x;
    }
    return a.type < b.type;
}

int main(){
    FAST_IO;

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i].l >> a[i].r >> a[i].f;
        CR.push_back(a[i].r);
        CR.push_back(a[i].l + a[i].f);
        CD.push_back(a[i].r - a[i].l);
        CD.push_back(a[i].f);
    }

    sort(ALL(CR));
    CR.erase(unique(ALL(CR)), CR.end());

    sort(ALL(CD));
    CD.erase(unique(ALL(CD)), CD.end());

    bitR.init((int)CR.size());
    bitD.init((int)CD.size());

    vector<pair<ll, int>> seg;
    vector<Query> qu;

    for(int i = 1; i <= n; i++){
        seg.push_back({a[i].l, i});
        Query cur;
        cur.l = a[i].l;
        cur.A = a[i].l + a[i].f;
        cur.id = i;
        qu.push_back(cur);
    }

    sort(ALL(seg));
    sort(ALL(qu), cmpQuery);

    int ptr = 0;
    int curCnt = 0;

    for(Query q : qu){
        while(ptr < (int)seg.size() && seg[ptr].first <= q.l){
            int id = seg[ptr].second;
            bitR.update(getR(a[id].r), 1);
            curCnt++;
            ptr++;
        }

        int pos = getR(q.A);
        res[q.id] += curCnt - bitR.get(pos - 1);
    }

    vector<Event> events;

    for(int i = 1; i <= n; i++){
        ll B = a[i].r - a[i].f;
        Event e1;
        e1.x = B;
        e1.f = a[i].f;
        e1.id = i;
        e1.type = 1;
        events.push_back(e1);
        Event e2;
        e2.x = a[i].l;
        e2.f = a[i].f;
        e2.id = i;
        e2.type = -1;
        events.push_back(e2);
    }

    sort(ALL(events), cmpEvent);

    ptr = 0;
    curCnt = 0;

    for(Event e : events){
        while(ptr < (int)seg.size() && seg[ptr].first <= e.x){
            int id = seg[ptr].second;
            bitD.update(getD(a[id].r - a[id].l), 1);
            curCnt++;
            ptr++;
        }

        int pos = getD(e.f);
        ll cnt = curCnt - bitD.get(pos - 1);
        res[e.id] += 1LL * e.type * cnt;
    }

    for(int i = 1; i <= n; i++) res[i]--;

    for(int i = 1; i <= n; i++) cout << res[i] << ' ';

    return 0;
}