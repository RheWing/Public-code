#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 100005;
const int MAXV = 100005;

struct Query{
    int l, r, t, id;
};

struct Update{
    int pos;
    int oldVal;
    int newVal;
};

int N, Q;
int a[MAXN];
int curA[MAXN];
vector<Query> qu;
vector<Update> updates;

int BLOCK = 2200;

bool cmp(Query A, Query B){
    int blockL1 = A.l / BLOCK;
    int blockL2 = B.l / BLOCK;
    if(blockL1 != blockL2) return blockL1 < blockL2;

    int blockR1 = A.r / BLOCK;
    int blockR2 = B.r / BLOCK;
    if(blockR1 != blockR2){
        if(blockL1 & 1) return blockR1 > blockR2;
        return blockR1 < blockR2;
    }

    if(blockR1 & 1) return A.t > B.t;
    return A.t < B.t;
}

int freq[MAXV];
int dCnt;

void add(int pos){
    int x = curA[pos];
    if(freq[x] == 0) dCnt++;
    freq[x]++;
}

void removePos(int pos){
    int x = curA[pos];
    freq[x]--;
    if(freq[x] == 0) dCnt--;
}

void applyUpdate(int idx, int L, int R){
    int pos = updates[idx].pos;
    int val = updates[idx].newVal;
    if(L <= pos && pos <= R){
        removePos(pos);
        curA[pos] = val;
        add(pos);
    }
    else{
        curA[pos] = val;
    }
}

void rollbackUpdate(int idx, int L, int R){
    int pos = updates[idx].pos;
    int val = updates[idx].oldVal;
    if(L <= pos && pos <= R){
        removePos(pos);
        curA[pos] = val;
        add(pos);
    }
    else{
        curA[pos] = val;
    }
}

int res[MAXN];

int main(){
    FAST_IO;

    cin >> N >> Q;

    for(int i = 1; i <= N; i++){
        cin >> a[i];
        curA[i] = a[i];
    }

    int queryCnt = 0;

    for(int i = 1; i <= Q; i++){
        int t;
        cin >> t;
        if(t == 1){
            int p, x;
            cin >> p >> x;
            Update u;
            u.pos = p;
            u.oldVal = curA[p];
            u.newVal = x;
            curA[p] = x;

            updates.push_back(u);
        }
        else{
            int l, r;
            cin >> l >> r;
            Query q;
            q.l = l;
            q.r = r;
            q.t = (int)updates.size();
            q.id = ++queryCnt;

            qu.push_back(q);
        }
    }

    for(int i = 1; i <= N; i++){
        curA[i] = a[i];
    }

    sort(qu.begin(), qu.end(), cmp);

    int curL = 1;
    int curR = 0;
    int curT = 0;

    for(Query q : qu){
        while(curT < q.t){
            applyUpdate(curT, curL, curR);
            curT++;
        }
        while(curT > q.t){
            curT--;
            rollbackUpdate(curT, curL, curR);
        }
        while(curL > q.l){
            curL--;
            add(curL);
        }
        while(curR < q.r){
            curR++;
            add(curR);
        }
        while(curL < q.l){
            removePos(curL);
            curL++;
        }
        while(curR > q.r){
            removePos(curR);
            curR--;
        }

        res[q.id] = dCnt;
    }

    for(int i = 1; i <= queryCnt; i++){
        cout << res[i] << '\n';
    }

    return 0;
}