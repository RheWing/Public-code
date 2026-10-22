#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".inp","r",stdin); freopen(task".out","w",stdout);
#define task "shopping"

int n;
vector<string> a;

string add(string s){
    int i = s.length() - 1;
    while(i >= 0 && s[i] == '9'){
        s[i] = '0';
        i--;
    }
    if(i < 0) s = "1" + s;
    else s[i]++;
    return s;
}

string solve(string str){
    string s = add(str);
    while(1){
        int w = -1;
        int len = s.length();
        for(int i = 0; i < len - 1; i++){
            if(s[i] < s[i + 1]){
                w = i;
                break;
            }
        }
        if(w == -1) break;
        s[w]++; 
        for(int j = w + 1; j < len; j++) s[j] = '0';
    }
    
    return s;
}

bool check(string s){
    int len = s.length();
    if(len <= 1) return 1;
    for(int i = 0; i < len - 1; i++) if(s[i] < s[i + 1]) return 0;
    return 1;
}

int main(){
    FAST_IO
    FILE_IO

    cin >> n;

    for(int i = 1; i <= n; i++){
        string s; cin >> s;
        a.push_back(s);
    }

    for(string s : a){
        if(check(s)) cout << s << ' ';
        else cout << solve(s) << ' ';
    }

    return 0;
}