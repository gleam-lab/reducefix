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
        ll h = H[i];
        // Each full cycle of 3 attacks deals 5 damage (1+1+3)
        ll cycles = h / 5;
        T += 3 * cycles;
        h -= 5 * cycles;
        // Handle remaining health
        while (h > 0) {
            T++;
            if (T % 3 == 0) {
                h -= 3;
            } else {
                h -= 1;
            }
        }
    }
    cout << T << endl;
    return 0;
}