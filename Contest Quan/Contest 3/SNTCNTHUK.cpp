#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);

const int MAXP = 1000001;
int min_prime[MAXP];

int divv[1 << 7];  
int sgn[1 << 7];
int sz;

void sieve(){
    for(int i = 2; i < MAXP; i++){
        if(min_prime[i] == 0){
            for(int j = i; j < MAXP; j += i){
                if(min_prime[j] == 0) min_prime[j] = i;
            }
        }
    }
}

void build(int p){
    sz = 1;
    divv[0] = 1;
    sgn[0] = 1;
    while(p > 1){
        int pr = min_prime[p];
        while(p % pr == 0) p /= pr;
        for(int i = 0; i < sz; i++){
            divv[sz + i] = divv[i] * pr;
            sgn[sz + i] = -sgn[i];
        }
        sz <<= 1;
    }
}

int BHLT(int n){
    int cnt = 0;
    for(int i = 0; i < sz; i++){
        cnt += sgn[i] * (n / divv[i]);
    }
    return cnt;
}

int main(){
    FAST_IO
    sieve();

    int t;
    cin >> t;
    while(t--){
        int x, p, k;
        cin >> x >> p >> k;

        build(p);

        int phi = BHLT(p);
        ll need = (ll)BHLT(x) + k; 

        ll q = (need - 1) / phi;
        int r = (int)((need - 1) % phi) + 1;

        int l = 1, h = p, res = p;
        while(l <= h){
            int mid = (l + h) >> 1;
            if(BHLT(mid) >= r){
                res = mid;
                h = mid - 1;
            } else{
                l = mid + 1;
            }
        }

        cout << q * p + res << "\n";
    }
    return 0;
}