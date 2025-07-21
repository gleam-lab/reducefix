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

    // We'll use a priority queue to always attack the frontmost enemy with health > 0
    // Each enemy will be represented as a pair of (negative health, index)
    // So we can simulate the attacks in order

    // However, we need to simulate time T carefully
    // When we perform an attack at time T:
    // - If T % 3 == 0: damage is 3
    // - Else: damage is 1

    // Optimization: Instead of simulating every single attack,
    // we calculate how many attacks are needed for each enemy to die,
    // considering triple attacks and single attacks.

    ll T = 0;
    ll tri = 0; // Number of ticks that are multiples of 3
    ll single = 0; // Number of ticks that are not multiples of 3

    // To determine if a new tick is a triple or single attack,
    // we need to track current T value

    for (ll i = 0; i < n; ++i) {
        ll h = H[i];

        if (h <= 0) continue;

        // For each enemy, we need to simulate attacks until its health <= 0

        // Every 3 attacks, we have one triple attack (damage 3)
        // and two single attacks (damage 1 each)

        // Let's calculate how many full cycles of 3 attacks are needed
        // One cycle: 3 attacks -> 3+1+1 = 5 damage total

        ll full_cycles = h / 5;
        ll remaining_health = h % 5;

        T += full_cycles * 3;

        // Now handle remaining health
        // After full cycles, we need additional attacks depending on remaining_health
        while (remaining_health > 0) {
            T++;
            if (T % 3 == 0) {
                remaining_health -= 3;
            } else {
                remaining_health -= 1;
            }
        }
    }

    cout << T << endl;
}