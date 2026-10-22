#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);

const int MAXN = 100005;

int n;
ll a[MAXN], b[MAXN];
int mu[MAXN];
int st[MAXN + 2];
int cntd[MAXN];
vector<int> sd;

int gcd(int a, int b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void upd(int y, int delta){
    for(int t = st[y]; t < st[y + 1]; t++){
        cntd[abs(sd[t])] += delta;
    }
}

int BHLT(int x){
    int s = 0;
    for(int t = st[x]; t < st[x + 1]; t++){
        int v = sd[t];
        if(v > 0) s += cntd[v];
        else s -= cntd[-v];
    }
    return s;
}

ll solve(ll A[], ll B[], int k){
    int m = n / k;
    vector<int> X(m), Y(m);

    for(int i = 0; i < m; i++){
        X[i] = i + 1;
        Y[i] = i + 1;
    }

    sort(X.begin(), X.end(), [&](int p, int q){
        return A[(ll)k * p] > A[(ll)k * q];
    });

    sort(Y.begin(), Y.end(), [&](int p, int q){
        return B[(ll)k * p] < B[(ll)k * q];
    });

    for(int d = 1; d <= m; d++){
        cntd[d] = 0;
    }

    for(int i = 0; i < m; i++){
        upd(Y[i], 1);
    }

    int hi = m;
    ll best = LLONG_MIN;

    for(int i = 0; i < m; i++){
        int x = X[i];
        ll ax = A[(ll)k * x];

        while(hi > 0 && best != LLONG_MIN && ax - B[(ll)k * Y[hi - 1]] <= best){
            hi--;
            upd(Y[hi], -1);
        }

        if(hi == 0){
            break;
        }

        int c = BHLT(x);

        if(c > 0){
            int last = -1;
            while(c > 0){
                hi--;
                int y = Y[hi];
                upd(y, -1);
                if(gcd(x, y) == 1){
                    c--;
                    last = y;
                }
            }
            best = ax - B[(ll)k * last];
        }
    }

    return best;
}

int main(){
    FAST_IO

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }

    vector<int> primes;
    vector<bool> comp(n + 1, false);
    mu[1] = 1;

    for(int i = 2; i <= n; i++){
        if(!comp[i]){
            primes.push_back(i);
            mu[i] = -1;
        }
        for(int p : primes){
            if((ll)i * p > n){
                break;
            }
            comp[i * p] = true;
            if(i % p == 0){
                mu[i * p] = 0;
                break;
            }
            mu[i * p] = -mu[i];
        }
    }

    for(int d = 1; d <= n; d++){
        if(mu[d] != 0){
            for(int j = d; j <= n; j += d){
                st[j + 1]++;
            }
        }
    }

    for(int i = 1; i <= n + 1; i++){
        st[i] += st[i - 1];
    }

    sd.assign(st[n + 1], 0);
    vector<int> pos(st, st + n + 2);

    for(int d = 1; d <= n; d++){
        if(mu[d] != 0){
            for(int j = d; j <= n; j += d){
                sd[pos[j]++] = mu[d] * d;
            }
        }
    }

    for(int k = 1; k <= n; k++){
        ll c = max(solve(a, b, k), solve(b, a, k));
        cout << c << ' ';
    }

    cout << '\n';

    return 0;
}