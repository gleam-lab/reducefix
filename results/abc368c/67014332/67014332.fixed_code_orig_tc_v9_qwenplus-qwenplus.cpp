#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;

    vector<ll> H(N);
    for (ll i = 0; i < N; ++i) {
        cin >> H[i];
    }

    // We will simulate the attack process using a priority queue
    // Each enemy is represented by its current health and position
    // We use a min-heap based on the next time it should be attacked

    // To efficiently determine which enemy to attack at each step T,
    // we can maintain a priority queue of when enemies will be attacked again.

    // For each enemy, we calculate how many attacks are needed to reduce its health to 0.
    // The problem becomes simulating the turn-based attack system optimally.

    // Since we must attack the frontmost alive enemy every turn,
    // we need to simulate this correctly.

    // Optimization: Use a deque to keep track of live enemies
    deque<pair<ll, ll>> enemies;  // {health, index}
    for (ll i = 0; i < N; ++i) {
        if (H[i] > 0) {
            enemies.emplace_back(H[i], i);
        }
    }

    ll T = 0;
    while (!enemies.empty()) {
        T++;
        auto &[h, idx] = enemies.front();
        h -= (T % 3 == 0) ? 3 : 1;

        if (h <= 0) {
            enemies.pop_front();
        }
    }

    cout << T << "\n";
    return 0;
}