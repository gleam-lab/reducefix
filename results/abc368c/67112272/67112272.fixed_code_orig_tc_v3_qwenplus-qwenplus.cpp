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

    for (ll health : h) {
        ll full_cycles = health / 5;
        ll rem = health % 5;

        // Each full cycle takes 3 seconds and deals 5 damage
        ans += full_cycles * 3;

        if (rem > 0) {
            // After full cycles, check how many more attacks are needed
            if (rem <= 2) {
                ans += rem; // Just normal 1-damage hits
            } else {
                // At least one 3-damage hit needed
                ans += 2 + (rem - 3); // 1 turn with 3-damage + (rem - 3) turns with 1-damage
            }
        }
    }

    cout << ans << endl;
}