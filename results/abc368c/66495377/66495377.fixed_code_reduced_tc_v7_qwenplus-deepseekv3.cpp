#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll calculate_min_attacks(ll h) {
    ll low = 0;
    ll high = 2 * h; // Upper bound; could be optimized further
    ll result = high;
    
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        ll damage = (mid / 3) * 5;
        if (mid % 3 == 1) {
            damage += 1;
        } else if (mid % 3 == 2) {
            damage += 2;
        }
        
        if (damage >= h) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    
    ll total_attacks = 0;
    for (int i = 0; i < n; ++i) {
        ll required_attacks = calculate_min_attacks(h[i]);
        // The actual T is total_attacks + required_attacks, but we need to ensure that the attacks are sequential
        // So we need to find when the previous attacks affect the current enemy
        // Hence, we need to find T such that the cumulative attacks up to T reduce the current enemy's health to <=0
        // This problem is trickier because the attack pattern depends on the global T, not per enemy
        // The previous approach was wrong because it didn't account for the global T properly
        // So we need a different approach
        
        // Let's think differently: each attack affects the frontmost enemy with health >0
        // So the total T is the sum of all attacks needed to kill each enemy in sequence
        // But the attack pattern (damage) depends on the global T
        
        // The previous approach was treating each enemy independently, which is incorrect
        // So instead, we need to simulate or find a mathematical relation
        
        // Alternative idea: for each enemy, the number of attacks needed is the smallest t_i such that:
        // sum_{k=1 to t_i} (if (T_prev + k) % 3 == 0 then 3 else 1) >= H_i
        // Where T_prev is the total attacks before this enemy
        
        // This is difficult to compute directly, so perhaps binary search for t_i given T_prev
        
        // So we need a binary search for each enemy, but now involving T_prev
        
        // Let's implement this:
        ll low = 0;
        ll high = 2 * h[i];
        ll t_i = high;
        
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            ll damage = 0;
            ll T_start = total_attacks + 1;
            ll T_end = total_attacks + mid;
            
            // Number of full triplets in [T_start, T_end]
            ll full_cycles = (T_end / 3) - ((T_start - 1) / 3);
            damage += full_cycles * 3;
            
            // Remaining attacks not in full triplets
            ll remaining = mid - full_cycles * 3;
            damage += remaining;
            
            if (damage >= h[i]) {
                t_i = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        total_attacks += t_i;
    }
    
    cout << total_attacks << endl;
    
    return 0;
}