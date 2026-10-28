
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

const int MAXN = 305;

struct Point{
    ll x, y;
};

int n;
Point P[MAXN];
int billow[MAXN][MAXN];
ll res[MAXN];

ll cross(Point a, Point b, Point c){
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool cmp(Point a, Point b){
    if(a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

int main(){
    FAST_IO

    cin >> n;
    for(int i = 0; i < n; i++) cin >> P[i].x >> P[i].y;

    sort(P, P + n, cmp);

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = i + 1; k < j; k++){
                if(cross(P[i], P[j], P[k]) < 0) billow[i][j]++;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                int inside;
                if(cross(P[i], P[k], P[j]) > 0){
                    inside = billow[i][j] + billow[j][k] - billow[i][k];
                }else{
                    inside = billow[i][k] - billow[i][j] - billow[j][k] - 1;
                }

                res[inside]++;
            }
        }
    }

    for(int i = 0; i <= n - 3; i++){
        cout << res[i] << '\n';
    }

    return 0;
}
