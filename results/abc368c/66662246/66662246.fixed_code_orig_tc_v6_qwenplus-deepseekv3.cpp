#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> H(n);
    rep(i, n) cin >> H[i];
    ll T = 0;
    rep(i, n) {
        ll cycles = H[i] / 5;
        ll rem = H[i] % 5;
        T += cycles * 3;
        if (rem > 0) {
            if (rem <= 2) {
                T += rem;
            } else {
                T += 3 - (rem == 4 ? 1 : 0);
            }
        }
    }
    cout << T << endl;
}