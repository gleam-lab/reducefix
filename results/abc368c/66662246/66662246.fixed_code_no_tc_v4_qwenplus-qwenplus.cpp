#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

// Function to calculate the number of attacks needed for a single enemy
ll attacks_needed(ll health) {
    // Each cycle consists of 3 attacks:
    // - 1st attack: damage 1
    // - 2nd attack: damage 1
    // - 3rd attack: damage 3
    // Total damage per cycle: 5
    ll full_cycles = health / 5;
    ll remaining_health = health % 5;

    ll total_attacks = full_cycles * 3;

    if (remaining_health > 0) {
        total_attacks += 1; // First attack does 1 damage
        if (remaining_health > 1) {
            total_attacks += 1; // Second attack does 1 damage
            if (remaining_health > 2) {
                total_attacks += 1; // Third attack does 3 damage
            }
        }
    }

    return total_attacks;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<ll> H(n);
    rep(i, n) cin >> H[i];

    ll total_time = 0;
    multiset<ll> pq; // Priority queue to track enemies that need to be attacked

    // Initialize the priority queue with initial healths
    for (ll h : H) {
        if (h > 0) {
            pq.insert(h);
        }
    }

    while (!pq.empty()) {
        total_time++;

        // Get the frontmost enemy
        auto it = pq.begin();
        ll current_health = *it;
        pq.erase(it);

        // Apply attack based on T being multiple of 3 or not
        if (total_time % 3 == 0) {
            current_health -= 3;
        } else {
            current_health -= 1;
        }

        if (current_health > 0) {
            pq.insert(current_health); // Enemy still has health left
        }
    }

    cout << total_time << endl;
    return 0;
}