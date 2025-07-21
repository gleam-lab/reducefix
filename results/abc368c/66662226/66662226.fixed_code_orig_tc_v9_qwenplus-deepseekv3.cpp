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
        if (i > 0 && H[i-1] > 0) {
            ll prev_attacks = (H[i-1] + 2) / 3; // Equivalent to ceil(H[i-1] / 3)
            h = max(0LL, h - prev_attacks * 2);
        }
        ll full_cycles = h / 5;
        ans += full_cycles * 3;
        h -= full_cycles * 5;
        while (h > 0) {
            ans++;
            if (ans % 3 == 0) {
                h -= 3;
            } else {
                h -= 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}