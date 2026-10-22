#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task "TIME"

const int MAXN = 1000005;
stack<int> st;
vector<int> order;
bool del[MAXN];

int main() {
    FAST_IO
    FILE_IO

    int t; cin >> t;

    while(t--){
        string s; cin >> s;
        ll k; cin >> k;
        
        order.clear();
        int len = s.length();
        for(int i = 0; i < len; i++){
            while(st.size() && s[st.top()] > s[i]){
                order.push_back(st.top());
                st.pop();
            }
            st.push(i);
        }
        while(st.size()){
            order.push_back(st.top());
            st.pop();
        }

        int rem = 0;
        int x = len;
        while(k > x){
            k -= x;
            x--;
            rem++;
        }

        for(int i = 0; i < rem; i++){
            del[order[i]] = 1;
        }

        int cnt = 0;
        for(int i = 0; i < len; i++){
            if(del[i]) continue;
            cnt++;
            if(cnt == k){
                cout << s[i] << '\n';
                break;
            }
        }

        fill(del, del + MAXN, 0);
    }

    return 0;
}
