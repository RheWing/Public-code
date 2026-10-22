#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask,i) (((mask)>>(i))&1)
#define MASK(i) (1LL<<(i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""
const int MAXN = 100005;
const ll INF = 1e18;

struct DATA{
    ll A,B;
    int id;
};
DATA a[MAXN],b[MAXN];
int n,k;
ll D;

namespace Subtask1{
    void solve(){
        ll res = -1;
        for(int mask = 0; mask < (1 << n); mask++){
            if(__builtin_popcount(mask) != k){
                continue;
            }
            ll sum = 0;
            ll mn = INF;
            ll mx = -INF;
            for(int i = 0; i < n; i++){
                if(BIT(mask,i)){
                    sum += a[i].A;
                    mn = min(mn,a[i].B);
                    mx = max(mx,a[i].B);
                }
            }
            if(mx - mn <= D){
                res = max(res,sum);
            }
        }
        cout << res;
    }

}

namespace Subtask2{
    bool cmp(DATA x,DATA y){
        return x.B < y.B;
    }
    ll val[MAXN];
    void solve(){
        for(int i = 0; i < n; i++){
            b[i] = a[i];
        }
        sort(b,b + n,cmp);
        ll res = -1;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = i + 1; j < n; j++){
                if(b[j].B - b[i].B <= D){
                    val[cnt++] = b[j].A;
                }
                else{
                    break;
                }
            }
            if(cnt >= k - 1){
                sort(val,val + cnt,greater<ll>());
                ll cur = b[i].A;
                for(int j = 0; j < k - 1; j++){
                    cur += val[j];
                }
                res = max(res,cur);
            }
        }
        cout << res;
    }

}

namespace Subtask3{
    ll val[MAXN];
    void solve(){
        for(int i = 0; i < n; i++){
            val[i] = a[i].A;
        }
        sort(val,val + n,greater<ll>());
        ll res = 0;
        for(int i = 0; i < k; i++){
            res += val[i];
        }
        cout << res;
    }

}

namespace Subtask4{
    struct Node{
        int cnt;
        ll sum;
    };
    Node st[4 * MAXN];
    ll comp[MAXN];
    int sz;
    bool cmp(DATA x,DATA y){
        return x.B < y.B;
    }
    int getID(ll x){
        return lower_bound(comp + 1,comp + sz + 1,x) - comp;
    }
    void update(int id,int l,int r,int pos,int addCnt,ll addVal){
        st[id].cnt += addCnt;
        st[id].sum += 1LL * addCnt * addVal;
        if(l == r){
            return;
        }
        int mid = (l + r) >> 1;
        if(pos <= mid){
            update(id * 2,l,mid,pos,addCnt,addVal);
        }
        else{
            update(id * 2 + 1,mid + 1,r,pos,addCnt,addVal);
        }
    }
    ll query(int id,int l,int r,int need){
        if(need <= 0){
            return 0;
        }
        if(st[id].cnt <= need){
            return st[id].sum;
        }
        if(l == r){
            return 1LL * need * comp[l];
        }
        int mid = (l + r) >> 1;
        if(st[id * 2 + 1].cnt >= need){
            return query(id * 2 + 1,mid + 1,r,need);
        }
        return st[id * 2 + 1].sum +
               query(id * 2,l,mid,need - st[id * 2 + 1].cnt);
    }

    void solve(){
        for(int i = 0; i < n; i++){
            b[i] = a[i];
        }
        sort(b,b + n,cmp);
        sz = 0;
        for(int i = 0; i < n; i++){
            comp[++sz] = b[i].A;
        }
        sort(comp + 1,comp + sz + 1);
        sz = unique(comp + 1,comp + sz + 1) - comp - 1;
        ll res = -1;
        int R = 0;
        for(int L = 0; L < n; L++){
            if(R <= L){
                R = L + 1;
            }
            while(R < n && b[R].B - b[L].B <= D){
                int pos = getID(b[R].A);
                update(1,1,sz,pos,1,b[R].A);
                R++;
            }
            int available = R - L - 1;
            if(available >= k - 1){
                ll cur = b[L].A + query(1,1,sz,k - 1);
                res = max(res,cur);
            }
            if(L + 1 < R){
                int pos = getID(b[L + 1].A);
                update(1,1,sz,pos,-1,b[L + 1].A);
            }
        }
        cout << res;
    }

}

int main(){
    FAST_IO

    cin >> n >> k >> D;

    for(int i = 0; i < n; i++){
        cin >> a[i].A >> a[i].B;
        a[i].id = i;
    }

    if(n <= 20){
        Subtask1::solve();
    }
    else if(n <= 2000){
        Subtask2::solve();
    }
    else if(D == 1000000000LL){
        Subtask3::solve();
    }
    else{
        Subtask4::solve();
    }

    return 0;
}