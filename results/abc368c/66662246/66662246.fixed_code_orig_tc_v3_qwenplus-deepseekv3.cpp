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
        // The number of full cycles (3 attacks: 1,1,3) is (hi / 5)
        // Because each cycle of 3 attacks deals 1 + 1 + 3 = 5 damage
        ll cycles = hi / 5;
        ans += cycles * 3;
        hi -= cycles * 5;
        // Now handle the remaining health (0 < hi <= 4)
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
}