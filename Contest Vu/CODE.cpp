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

int n, q;
int a[MAXN];
int B;
int cnt[320][MAXV];

int main(){
    FAST_IO

    cin >> n >> q;

    B = sqrt(n);

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        cnt[i / B][a[i]]++;
    }

    while(q--){
        int t;
        cin >> t;

        if(t == 1){
            int p, x;
            cin >> p >> x;

            int block = p / B;
            cnt[block][a[p]]--;
            cnt[block][x]++;
            a[p] = x;
        }
        else{
            int l, r, x;
            cin >> l >> r >> x;

            int res = 0;
            int blockL = l / B;
            int blockR = r / B;

            if(blockL == blockR){
                for(int i = l; i <= r; i++) if(a[i] == x) res++;
            }
            else {
                int endL = (blockL + 1) * B - 1;

                for(int i = l; i <= min(r, endL); i++) if(a[i] == x) res++;

                for(int b = blockL + 1; b < blockR; b++) res += cnt[b][x];

                for(int i = blockR * B; i <= r; i++) if(a[i] == x) res++;
            }

            cout << res << '\n';
        }
    }

    return 0;
}