#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

// Function to compute the minimum number of attacks needed for one enemy
ll compute_attacks(ll h) {
    // Each attack cycle of 3 seconds: two 1-damage attacks and one 3-damage attack
    // In 3 seconds -> 5 damage total
    ll full_cycles = h / 5;
    ll remaining = h % 5;
    ll time = full_cycles * 3;
    
    if (remaining > 0) {
        time += 1; // At least one more attack
        if (remaining > 1) {
            time += 1; // Second attack needed
            if (remaining > 2) {
                time += 1; // Third attack needed
            }
        }
    }
    return time;
}

int main() {
    int n;
    cin >> n;
    vector<ll> H(n);
    rep(i, n) cin >> H[i];

    ll ans = 0;
    ll carry = 0; // Tracks how much damage has been carried over from previous enemies

    for (ll h : H) {
        h -= carry;
        if (h <= 0) {
            carry = 0;
            continue;
        }

        ll attacks_needed = compute_attacks(h);
        ans += attacks_needed;
        
        // Calculate how many attacks fall on multiples of 3 (3-damage attacks)
        ll three_damage_attacks = attacks_needed / 3;
        ll remaining_attacks = attacks_needed % 3;

        // Total damage dealt in this segment
        ll total_damage = three_damage_attacks * 3 + (attacks_needed - three_damage_attacks) * 1;
        carry = total_damage - h;
    }

    cout << ans << endl;
}