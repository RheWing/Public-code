#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

struct Rect{
    int x1, y1, x2, y2;
};

int n;
vector<int> valX, valY;

int main(){
    FAST_IO

    cin >> n;

    vector<Rect> re(n);

    for(int i = 0; i < n; i++){
        cin >> re[i].x1 >> re[i].y1 >> re[i].x2 >> re[i].y2;
        valX.push_back(re[i].x1);
        valX.push_back(re[i].x2);
        valY.push_back(re[i].y1);
        valY.push_back(re[i].y2);
    }

    sort(valX.begin(), valX.end());
    valX.erase(unique(valX.begin(), valX.end()), valX.end());

    sort(valY.begin(), valY.end());
    valY.erase(unique(valY.begin(), valY.end()), valY.end());

    int numX = valX.size();
    int numY = valY.size();

    vector<vector<bool>> co(numX - 1, vector<bool>(numY - 1, false));

    for(auto r : re){
        int idxX1 = lower_bound(valX.begin(), valX.end(), r.x1) - valX.begin();
        int idxX2 = lower_bound(valX.begin(), valX.end(), r.x2) - valX.begin();
        int idxY1 = lower_bound(valY.begin(), valY.end(), r.y1) - valY.begin();
        int idxY2 = lower_bound(valY.begin(), valY.end(), r.y2) - valY.begin();

        for(int i = idxX1; i < idxX2; i++){
            for(int j = idxY1; j < idxY2; j++){
                co[i][j] = true;
            }
        }
    }

    ll res = 0;
    for(int i = 0; i < numX - 1; i++){
        for(int j = 0; j < numY - 1; j++){
            if(co[i][j]){
                ll w = valX[i + 1] - valX[i];
                ll h = valY[j + 1] - valY[j];
                res += w * h;
            }
        }
    }

    cout << res << "\n";

    return 0;
}
