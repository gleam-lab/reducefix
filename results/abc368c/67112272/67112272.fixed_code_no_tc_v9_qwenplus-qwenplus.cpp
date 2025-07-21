#include <bits/stdc++.h>
using namespace std;

using ll = long64_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> H(n);
    for (int i = 0; i < n; ++i) {
        cin >> H[i];
    }

    ll time = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

    // Initialize: store the number of attacks needed and enemy index
    for (int i = 0; i < n; ++i) {
        if (H[i] > 0) {
            // Estimate how many turns needed to kill this enemy
            ll attacks = (H[i] + 2) / 3; // ceil(H[i]/3)
            pq.emplace(attacks, i);
        }
    }

    while (!pq.empty()) {
        auto [attacks_needed, idx] = pq.top();
        pq.pop();

        // If this enemy is already handled, skip
        if (attacks_needed == 0) continue;

        time += 1;

        // If T is a multiple of 3, deal 3 damage, else deal 1 damage
        if (time % 3 == 0) {
            H[idx] -= 3;
        } else {
            H[idx] -= 1;
        }

        if (H[idx] > 0) {
            // Recalculate attacks needed and push back if still alive
            ll new_attacks_needed = (H[idx] + 2) / 3;
            pq.push({new_attacks_needed, idx});
        }
    }

    cout << time << endl;
    return 0;
}