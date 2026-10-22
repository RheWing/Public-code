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

int n;
ll a[MAXN];
multiset<ll> L, R;
ll sumL = 0, sumR = 0;
ll tagR = 0;

ll getR(ll val) {
    return val + tagR;
}

void addL(ll val) {
    L.insert(val);
    sumL += val;
}

void addR(ll val) {
    R.insert(val - tagR);
    sumR += val;
}

void eraseL(multiset<ll>::iterator it) {
    sumL -= *it;
    L.erase(it);
}

void eraseR(multiset<ll>::iterator it) {
    sumR -= getR(*it);
    R.erase(it);
}

void balance() {
    int total = L.size() + R.size();
    int targetL = (total + 1) / 2;

    while ((int)L.size() > targetL) {
        auto it = prev(L.end());
        ll val = *it;
        eraseL(it);
        addR(val);
    }

    while ((int)L.size() < targetL) {
        auto it = R.begin();
        ll val = getR(*it);
        eraseR(it);
        addL(val);
    }
}

ll get_cost(ll k) {
    ll m_cntL = L.size();
    ll m_cntR = R.size();
    ll lcost = k * m_cntL - sumL;
    ll rcost = sumR - k * m_cntR;

    return lcost + rcost;
}

int main() {
    FAST_IO

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    addL(a[1] - 1);
    tagR = 0;
    for (int j = 2; j <= n; j++) {
        addR(a[j] + j - 2);
    }

    balance();

    ll res = 2e18;

    for (int p = 1; p <= n; p++) {
        ll med = *prev(L.end());
        ll k_min = max(0LL, (ll)n - 2LL * p + 1);
        ll k = max(med, k_min);

        res = min(res, get_cost(k));

        if (p < n) {
            tagR -= 2;
            ll val_in_R = a[p + 1] + (p + 1) - 2 * p;
            auto it = R.find(val_in_R - (tagR + 2)); 
            if (it != R.end()) {
                eraseR(it);
            }
            addL(a[p + 1] - (p + 1));

            balance();
        }
    }

    cout << res << "\n";

    return 0;
}