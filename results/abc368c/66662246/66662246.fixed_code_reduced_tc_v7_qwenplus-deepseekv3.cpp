#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];
    ll ans = 0;
    rep(i, n) {
        ll hi = h[i];
        if (hi <= 0) continue;
        // Calculate full cycles of 3 attacks (5 damage per cycle)
        ll full_cycles = hi / 5;
        ans += full_cycles * 3;
        hi -= full_cycles * 5;
        // Handle remaining attacks
        while (hi > 0) {
            ans++;
            if (ans % 3 == 0) {
                hi -= 3;
            } else {
                hi -= 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}