#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

struct B{
    ll w, s;
};

bool compB(const B& a, const B& b){
    return (a.w + a.s) < (b.w + b.s);
}

int main(){
    FAST_IO

    int n; cin >> n;

    vector<B> br(n);
    for(int i = 0; i < n; i++){
        cin >> br[i].w >> br[i].s;
    }

    sort(br.begin(), br.end(), compB);
    priority_queue<ll> max_heap; 
    ll cur_w = 0;

    for(int i = 0; i < n; i++){
        if(cur_w <= br[i].s){
            cur_w += br[i].w;
            max_heap.push(br[i].w);
        } else if(!max_heap.empty() && max_heap.top() > br[i].w) {
            cur_w -= max_heap.top();
            max_heap.pop();
            cur_w += br[i].w;
            max_heap.push(br[i].w);
        }
    }

    cout << max_heap.size() << "\n";

    return 0;
}
