#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> H(n);
    for (int i = 0; i < n; ++i) {
        cin >> H[i];
    }

    ll T = 0;
    priority_queue<pair<ll, int>> pq; // max-heap: (next attack time, enemy index)

    // Initialize with the first attack time as 1 for each enemy
    for (int i = 0; i < n; ++i) {
        if (H[i] > 0) {
            pq.push({-1, i}); // Use negative for min-heap behavior
        }
    }

    while (!pq.empty()) {
        auto [t_neg, idx] = pq.top();
        pq.pop();
        ll t = -t_neg;

        // If this enemy is already dead, skip
        if (H[idx] <= 0) continue;

        // Attack the enemy
        if (t % 3 == 0) {
            H[idx] -= 3;
        } else {
            H[idx] -= 1;
        }

        // If enemy still has health, schedule next attack
        if (H[idx] > 0) {
            pq.push({-(t + 1), idx});
        }
    }

    cout << t << endl;
}