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
        // Calculate full cycles of 3 attacks (1+1+3 = 5 damage)
        ll full_cycles = h / 5;
        ans += full_cycles * 3;
        h -= full_cycles * 5;
        // Process remaining health
        while (h > 0) {
            ans++;
            if (ans % 3 == 0) {
                h -= 3;
            } else {
                h--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}