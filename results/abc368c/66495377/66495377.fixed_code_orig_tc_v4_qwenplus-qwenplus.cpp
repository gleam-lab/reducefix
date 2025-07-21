#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Check if all enemies are defeated with given T attacks
bool is_enough(ll T, const vector<ll>& H) {
    ll n = H.size();
    vector<ll> damage(n, 0);
    
    // We simulate the attack pattern:
    // - Every 3rd attack does 3 damage
    // - All others do 1 damage
    // But we need to apply these attacks to enemies in order
    // and track how many attacks reach each enemy

    // For each time step from 1 to T
    // attack the first living enemy
    // so we must keep track of which enemy is currently being attacked

    ll current_enemy = 0;
    for (ll t = 1; t <= T && current_enemy < n; ++t) {
        // At time t, attack current_enemy
        ll dmg = (t % 3 == 0) ? 3 : 1;
        H[current_enemy] -= dmg;
        if (H[current_enemy] <= 0) {
            current_enemy++;
        }
    }
    
    return current_enemy >= n;
}

ll solve(const vector<ll>& H) {
    ll n = H.size();
    vector<ll> H_copy = H;

    // Binary search on T
    ll low = 0;
    ll high = 2e18; // large upper bound

    while (low < high) {
        ll mid = (low + high) / 2;
        if (is_enough(mid, H_copy)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    return low;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<ll> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    cout << solve(H) << "\n";
    return 0;
}