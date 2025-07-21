#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> H(n);
    for (ll i = 0; i < n; ++i) {
        cin >> H[i];
    }

    // We'll simulate the process efficiently using a priority queue
    // Only attack enemies with health > 0
    // At each T, we attack the frontmost enemy

    // We maintain a variable T for time
    // We also keep track of how many triple damage attacks have occurred (every 3rd attack)
    ll T = 0;
    ll tri_count = 0; // number of times triple damage has been used in current cycle

    // To optimize, we simulate how many full cycles of attacks are needed
    // before reaching the point where we can finish off all enemies
    // For each enemy, we calculate how much damage it needs and simulate accordingly.

    // We will process each enemy one by one
    for (ll i = 0; i < n; ++i) {
        ll h = H[i];

        // While this enemy still has health > 0
        while (h > 0) {
            T++;
            tri_count++;

            // Every 3rd attack does triple damage
            if (tri_count == 3) {
                h -= 3;
                tri_count = 0;
            } else {
                h -= 1;
            }
        }
    }

    cout << T << endl;
    return 0;
}