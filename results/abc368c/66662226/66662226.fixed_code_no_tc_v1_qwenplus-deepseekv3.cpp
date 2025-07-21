#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> H(n);
    rep(i, n) cin >> H[i];
    ll ans = 0;
    rep(i, n) {
        ll h = H[i];
        // The pattern is 1,1,3,... so every 3 steps deal 5 damage (1+1+3)
        ll full_cycles = h / 5;
        ans += full_cycles * 3;
        h -= full_cycles * 5;
        // Now handle the remaining h (0 <= h <5)
        if (h > 0) {
            if (h <= 1) {
                ans += 1;
            } else if (h <= 2) {
                ans += 2;
            } else {
                ans += 3;
            }
        }
    }
    cout << ans << endl;
    return 0;
}