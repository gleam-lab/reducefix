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

    // We'll use a priority queue to process enemies in order of their position
    // We simulate the attack rounds, keeping track of time T
    ll T = 0;
    queue<pair<ll, ll>> enemies;  // {time_to_kill, enemy_index}
    
    for (ll i = 0; i < N; ++i) {
        if (H[i] == 0) continue;
        // Calculate how many attacks needed to kill this enemy
        ll attacks_needed = (H[i] + 2) / 3;  // ceil(H[i]/3)
        enemies.push({attacks_needed, i});
    }

    while (!enemies.empty()) {
        auto [attacks_needed, idx] = enemies.front();
        enemies.pop();
        
        T++;
        
        // If it's a multiple of 3, deal 3 damage, else deal 1 damage
        if (T % 3 == 0) {
            attacks_needed--;
        } else {
            attacks_needed--;
        }
        
        if (attacks_needed > 0) {
            enemies.push({attacks_needed, idx});
        }
    }

    cout << T << "\n";
    return 0;
}