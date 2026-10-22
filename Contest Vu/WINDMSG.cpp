#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","ll",stdout);
#define task ""
#define MAXN 100005
#define INF 1e9 + 7

const ll MOD1 = 1000000007;
const ll MOD2 = 1000000009;
const ll BASE1 = 31;
const ll BASE2 = 37;

int N, K;
string S;

vector<ll> pref1, pref2;
vector<ll> poll1, poll2;

void setup(){
    pref1.resize(N + 1, 0);
    pref2.resize(N + 1, 0);
    poll1.resize(N + 1, 1);
    poll2.resize(N + 1, 1);

    for(int i = 0; i < N; i++){
        pref1[i + 1] = (pref1[i] * BASE1 + (S[i] - 'a' + 1)) % MOD1;
        pref2[i + 1] = (pref2[i] * BASE2 + (S[i] - 'a' + 1)) % MOD2;
        poll1[i + 1] = (poll1[i] * BASE1) % MOD1;
        poll2[i + 1] = (poll2[i] * BASE2) % MOD2;
    }
}

pair<ll, ll> get_hash(int l, int r){
    ll h1 = (pref1[r] - pref1[l - 1] * poll1[r - l + 1]) % MOD1;
    if(h1 < 0) h1 += MOD1;

    ll h2 = (pref2[r] - pref2[l - 1] * poll2[r - l + 1]) % MOD2;
    if(h2 < 0) h2 += MOD2;

    return {h1, h2};
}

bool check(int len){
    vector<pair<ll, ll>> h;
    h.reserve(N - len + 1);

    for(int i = 1; i <= N - len + 1; i++){
        h.push_back(get_hash(i, i + len - 1));
    }

    sort(h.begin(), h.end());

    int cnt = 1;
    for(int i = 1; i < h.size(); i++){
        if(h[i] == h[i - 1]){
            cnt++;
        }else{
            cnt = 1;
        }
        if(cnt >= K) return true;
    }

    return cnt >= K;
}

int main() {
    FAST_IO

    cin >> N >> K;
    cin >> S;

    setup();

    int l = 1, r = N;
    int res = 0;

    while(l <= r){
        int mid = l + (r - l) / 2;
        if(check(mid)){
            res = mid;
            l = mid + 1; 
        }else{
            r = mid - 1;
        }
    }

    cout << res << "\n";

    return 0;
}