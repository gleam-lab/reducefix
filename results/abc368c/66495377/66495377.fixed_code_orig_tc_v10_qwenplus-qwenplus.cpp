#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Calculates the minimum number of attacks needed to reduce health h to 0,
// assuming each attack does either:
// - 3 damage if T is a multiple of 3
// - 1 damage otherwise
ll requiredAttacks(ll h) {
    // We want to maximize triple attacks (3 damage)
    // Each "good cycle" is 3 attacks: two 1-damage and one 3-damage
    // That gives 5 damage per 3 attacks
    
    ll full_cycles = h / 5;
    ll damage_from_full_cycles = full_cycles * 5;
    
    ll remaining_damage = h % 5;
    
    ll total_attacks = full_cycles * 3;
    
    // Handle remaining damage
    if (remaining_damage > 0) {
        total_attacks += 1;  // At least one more attack
    }
    if (remaining_damage > 1) {
        total_attacks += 1;  // Second attack may be needed
    }
    if (remaining_damage > 3) {
        total_attacks += 1;  // Third attack needed for remaining damage
    }
    
    return total_attacks;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<ll> H(n);
    for (int i = 0; i < n; ++i) {
        cin >> H[i];
    }
    
    // Binary search for the minimal time T that kills all enemies
    ll left = 0;
    ll right = 3 * 1e18; // Generous upper bound
    
    while (left < right) {
        ll mid = (left + right) / 2;
        
        ll current_time = 0;
        bool possible = true;
        
        for (ll h : H) {
            if (current_time >= mid) {
                possible = false;
                break;
            }
            
            ll attacks_needed = requiredAttacks(h);
            ll last_good_attack = mid - (mid % 3 == 0 ? 0 : (mid % 3));
            
            // Calculate how many good attacks (3x damage) we can make before enemy dies
            ll full_cycles = h / 5;
            ll remaining_damage = h % 5;
            ll good_attacks_needed = full_cycles + (remaining_damage > 0 ? 1 : 0);
            
            // Find the position of the last good attack needed
            ll last_our_good_attack = 3 * good_attacks_needed;
            
            if (last_our_good_attack <= mid) {
                // We can use good attacks for all triple attacks
                current_time += attacks_needed;
            } else {
                // We have to find how many bad attacks we need to insert
                ll good_attacks_possible = mid / 3;
                ll damage_from_goods = good_attacks_possible * 3;
                ll damage_remaining = max(0LL, h - damage_from_goods);
                
                ll bad_attacks_needed = damage_remaining;
                if (current_time + bad_attacks_needed > mid) {
                    possible = false;
                    break;
                }
                current_time += bad_attacks_needed;
            }
        }
        
        if (possible) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    cout << left << endl;
    return 0;
}