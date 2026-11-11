#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);

const int MAXV = 1000000;
const int MAXN = 200005;
int n, q;
int a[MAXN], val[MAXN], nxt[MAXN];
int head[MAXV + 5], spf[MAXV + 5];
vector<int> L[MAXV + 5];

void pushValue(int v){            
    int divs[512], cnt = 1;
    divs[0] = 1;
    int t = v;
    while(t > 1){
        int p = spf[t], e = 0;
        while(t % p == 0){ t /= p; e++; }
        int sz = cnt, mul = 1;
        for(int k = 1; k <= e; k++){
            mul *= p;
            for(int i = 0; i < sz; i++) divs[cnt++] = divs[i] * mul;
        }
    }
    for(int i = 0; i < cnt; i++)
        if(divs[i] > 1) L[divs[i]].push_back(v);
}

int main(){
    FAST_IO

    for(int i = 2; i <= MAXV; i++)
        if(spf[i] == 0)
            for(int j = i; j <= MAXV; j += i)
                if(spf[j] == 0) spf[j] = i;

    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        val[i] = a[i];
        if(a[i] >= 1 && head[a[i]] == 0) pushValue(a[i]);
        nxt[i] = head[a[i]];
        head[a[i]] = i;
    }

    vector<int> cur;
    while(q--){
        int x; cin >> x;
        if(x <= 1) continue;

        cur.clear();
        swap(cur, L[x]);
        sort(cur.begin(), cur.end());
        cur.erase(unique(cur.begin(), cur.end()), cur.end());

        for(int v : cur){
            if(head[v] == 0) continue;
            int nval = v / x;
            int c = head[v], last = c;
            while(c != 0){
                val[c] = nval;
                last = c;
                c = nxt[c];
            }
            bool fresh = (head[nval] == 0);
            nxt[last] = head[nval];
            head[nval] = head[v];
            head[v] = 0;
            if(fresh) pushValue(nval);  
        }
    }

    for(int i = 1; i <= n; i++)
        cout << val[i] << (i == n ? '\n' : ' ');
    return 0;
}