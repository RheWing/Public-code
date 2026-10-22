#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task "PALIN"

string s;
int cnt[52];

int id(char c){
    if('A' <= c && c <= 'Z'){
        return c - 'A';
    }
    return c - 'a' + 26;
}

char revid(int x){
    if(x < 26){
        return char('A' + x);
    }
    return char('a' + x - 26);
}

bool palin(string s){
    int l = 0, r = (int)s.size() - 1;

    while(l < r){
        if(s[l] != s[r]){
            return false;
        }
        l++;
        r--;
    }

    return true;
}

int main(){
    FAST_IO
    FILE_IO

    cin >> s;

    if(palin(s)){
        cout << s;
        return 0;
    }

    for(char c : s){
        cnt[id(c)]++;
    }

    int le = 0;
    char mid;

    for(int i = 0; i < 52; i++){
        if(cnt[i] & 1){
            le++;
            mid = revid(i);
        }
    }

    if(le > 1){
        cout << "NO";
        return 0;
    }

    string l;
    for(int i = 0; i < 52; i++){
        l.append(cnt[i] / 2, revid(i));
    }
    string r = l;
    reverse(r.begin(), r.end());

    string res = l;
    if(le){
        res += mid;
    }
    res += r;

    cout << res;

    return 0;
}