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

int n, k;
int prime[MAXN], a[MAXN];

void sang(){
    for(int i = 1; i <= 100000; i++) prime[i] = 1;
    for(int i = 2; i * i <= 100000; i++){
        if(prime[i]){
            for(int j = i * i; j <= 100000; j += i){
                prime[j] = 0;
            }
        }
    }
}

int main(){
    FAST_IO

    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    sang();
    bool same = 1;
    for(int i = 1; i < n; i++){
        if(a[i] != a[i + 1]){
            same = 0;
            break;
        }
    }

    if(same){
        if(n == 1 && prime[a[1]]){
            cout << -1;
            return 0;
        }
        if(a[1] == 0){
            cout << n + 1 << '\n';
            for(int i = 1; i <= n + 1; i++) cout << 0 << ' ';
            return 0;
        }
        if(a[1] == 1){
            cout << -1;
            return 0;
        }
        if(a[1] == 2){
            if(k < 4){
                cout << -1;
                return 0;
            }
            cout << n - 1 << '\n';
            for(int i = 1; i <= n - 2; i++) cout << 2 << ' ';
            cout << 4;
            return 0;
        }
        else if(prime[a[1]]){
            cout << -1;
            return 0;
        }
        else{
            vector<int> p;
            int val = a[1];
            int x = -1;
            for(int i = 2; i * i <= val; i++){
                if(val % i == 0){
                    x = i;
                    break;
                }
            }
            int y = val / x;
            p.push_back(x);
            p.push_back(y);
            int z = val - (x + y);
            for(int i = 1; i <= z; i++) p.push_back(1);
            cout << n + 1 + z << '\n';
            for(int i = 1; i <= n - 1; i++) cout << a[i] << ' ';
            for(int i : p) cout << i << ' ';
            return 0;
        }
    }
    else{
        for(int i = 1; i < n; i++){
            if(a[i] != a[i + 1]){
                int tmp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = tmp;
                break;
            }
        }
        cout << n << '\n';
        for(int i = 1; i <= n; i++) cout << a[i] << ' ';
        return 0;
    }

    return 0;
}