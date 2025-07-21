#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

// Function to simulate attacks on a single enemy
ll simulate_attacks(int health) {
    ll t = 0;
    while (health > 0) {
        ++t;
        if (t % 3 == 0) {
            health -= 3;
        } else {
            health -= 1;
        }
    }
    return t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> H(n);
    for (int i = 0; i < n; ++i) {
        cin >> H[i];
    }

    // We will use a priority queue to always attack the hardest remaining enemy
    // Store enemies in a max-heap: we'll use negative values for max-heap behavior
    priority_queue<pair<ll, ll>> pq;
    
    // Initialize the queue with all enemies' health
    for (int i = 0; i < n; ++i) {
        if (H[i] > 0) {
            pq.push({-H[i], i});
        }
    }

    ll time = 0;
    ll total_attacks = 0;

    // Array to track how many times each enemy has been attacked
    vector<ll> attack_count(n, 0);

    while (!pq.empty()) {
        ++time;
        ++total_attacks;

        // Determine which enemy to attack (the one with highest remaining health)
        ll max_health = -pq.top().first;
        ll idx = pq.top().second;
        pq.pop();

        // Apply damage based on current time
        ll damage = (time % 3 == 0) ? 3 : 1;
        max_health -= damage;
        attack_count[idx] += damage;

        if (max_health > 0) {
            pq.push({-max_health, idx});
        }
    }

    // Calculate total time using attack count and position in sequence
    ll final_time = 0;
    for (int i = 0; i < n; ++i) {
        final_time += simulate_attacks(attack_count[i]);
    }

    cout << final_time << endl;

    return 0;
}