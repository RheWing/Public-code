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

int n, q;
vector<string> a;
bool val[MAXN];
int blockid[MAXN];
int posblock[MAXN];
vector<int> blockpos[MAXN];
bool pref[MAXN], suff[MAXN];
bool blockval[MAXN];
bool prefor[MAXN], suffor[MAXN];

int main(){
    FAST_IO

    cin >> n >> q;

    a.resize(n + 5);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    int numblock = 1;
    for(int i = 1; i <= n; i += 2){
        val[i] = (a[i] == "true");
        if(i > 1 && a[i - 1] == "or") numblock++;
        blockid[i] = numblock;
        blockpos[numblock].push_back(i);
    }

    for(int b = 1; b <= numblock; b++){
        int m = blockpos[b].size();
        for(int i = 0; i < m; i++){
            int p = blockpos[b][i];
            posblock[p] = i + 1;
        }
        for(int i = 0; i < m; i++){
            int p = blockpos[b][i];
            if(i == 0) pref[p] = val[p];
            else{
                int nxt = blockpos[b][i - 1];
                pref[p] = pref[nxt] & val[p];
            }
        }
        for(int i = m - 1; i >= 0; i--){
            int p = blockpos[b][i];
            if(i == m - 1) suff[p] = val[p];
            else{
                int nxt = blockpos[b][i + 1];
                suff[p] = suff[nxt] & val[p];
            }
        }
        int last = blockpos[b].back();
        blockval[b] = pref[last];
    }

    for(int i = 1; i <= numblock; i++){
        if(i == 1) prefor[i] = blockval[i];
        else prefor[i] = prefor[i - 1] | blockval[i]; 
    }

    for(int i = numblock; i >= 1; i--){
        if(i == numblock) suffor[i] = blockval[i];
        else suffor[i] = suffor[i + 1] | blockval[i];
    }

    string res = "";

    while(q--){
        int l, r;
        string v;
        cin >> l >> r >> v;

        bool w = (v == "true");
        int L = blockid[l];
        int R = blockid[r];

        bool out = 0;
        if(L > 1) out |= prefor[L - 1];
        if(R < numblock) out |= suffor[R + 1];

        bool lp = 1, rp = 1;

        int p1 = posblock[l];
        if(p1 > 1){
            int id1 = blockpos[L][p1 - 2];
            lp = pref[id1]; 
        }

        int p2 = posblock[r];
        int m = blockpos[R].size();
        if(p2 < m){
            int id2 = blockpos[R][p2];
            rp = suff[id2];
        }

        bool A = lp & rp;
        bool ok;
        if(!w) ok = !out;
        else ok = out | A;

        res.push_back(ok ? '1' : '0');
    }

    cout << res << '\n';

    return 0;
}