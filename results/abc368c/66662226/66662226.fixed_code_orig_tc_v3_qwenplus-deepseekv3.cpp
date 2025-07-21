#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];
    ll t = 0;
    rep(i, n) {
        ll hi = h[i];
        // The damage pattern is 1,1,3,1,1,3,...
        // So every 3 turns, the total damage is 5 (1+1+3)
        ll full_cycles = hi / 5;
        ll remaining = hi % 5;
        ll additional_attacks = 0;
        if (remaining > 0) {
            if (remaining <= 2) {
                additional_attacks = remaining;
            } else {
                additional_attacks = 3; // because 3rd attack is 3 damage
            }
        }
        t = max(t, full_cycles * 3 + additional_attacks);
    }
    // Now, verify if the max t is sufficient for all enemies
    // Because attacks are done in sequence, each enemy must be defeated by the time t reaches its required attacks
    // So we need to ensure that for each enemy, the total attacks up to their position is >= their required attacks
    // Thus, the total t is the maximum required by any enemy
    cout << t << endl;
    return 0;
}