#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define FILE_IO freopen(task".INP","r",stdin); freopen(task".OUT","w",stdout);
#define task ""

bitset<1000> khac[1000];
bitset<1000> bi_khac[1000]; 

template<size_t N>
int get_first_set_bit(const bitset<N>& bs) {
    for (size_t i = 0; i < N; i++) {
        if (bs[i]) {
            return i;
        }
    }
    return N;
}

int main() {
    FAST_IO

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            cin >> val;
            if (val == 1) {
                bi_khac[i].set(j); 
                khac[j].set(i); 
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (bi_khac[i].test(j)) { 
                bitset<1000> hop_le = bi_khac[j] & khac[i];
                
                if (hop_le.any()) {
                    int k = get_first_set_bit(hop_le); 
                    cout << (i + 1) << " " << (j + 1) << " " << (k + 1) << "\n";
                    return 0;
                }
            }
        }
    }

    cout << "-1 -1 -1\n";
    return 0;
}
