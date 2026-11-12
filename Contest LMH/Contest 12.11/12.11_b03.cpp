#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);

const int MAXN = 1e5 + 5;
struct Data {
    ll a, b;
};

int n;
ll s;
Data P[MAXN];

bool cmp(const Data& x, const Data& y){
    bool profx = (x.b >= x.a);
    bool profy = (y.b >= y.a);
    if(profx != profy){
        return profx > profy;
    }
    if(profx){
        return x.a < y.a;
    }
    return x.b > y.b;
}

int main(){
    FAST_IO

    cin >> n >> s;
    for(int i = 1; i <= n; i++){
        cin >> P[i].a >> P[i].b;
    }

    sort(P + 1, P + n + 1, cmp);

    int res = 0;
    priority_queue<ll> pq;  

    for(int i = 1; i <= n; i++){
        ll a = P[i].a, b = P[i].b;
        if(b >= a){
            if(s >= a){
                s += b - a;
                res++;
            }
        }
        else{
            ll d = a - b;
            if(s >= a){
                s -= d;
                pq.push(d);
                res++;
            }
            else if(!pq.empty() && pq.top() > d && s + pq.top() >= a){
                s += pq.top() - d;
                pq.pop();
                pq.push(d);
            }
        }
    }

    cout << res << '\n';

    return 0;
}