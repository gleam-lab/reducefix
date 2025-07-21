#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    for (auto &hi : h) cin >> hi;
    
    ll T = 0;
    for (auto hi : h) {
        // The current enemy will be attacked from T+1 onwards
        // We need to find the minimal x such that sum of damages >= hi
        // Damage pattern: 1, 1, 3, 1, 1, 3, ... (if T is 0 initially)
        // But T is increasing, so the first attack is at T+1, then T+2, etc.
        // So for enemy i, attacks occur at T+1, T+2, ..., T+k
        // Damage for each attack t is 3 if t % 3 == 0 else 1
        
        // Binary search for the minimal k such that sum_{t=T+1}^{T+k} damage(t) >= hi
        ll low = 1, high = 2 * hi; // Upper bound can be large, but 2*hi is safe
        ll k = 0;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll full_cycles = mid / 3;
            ll remainder = mid % 3;
            ll total_damage = full_cycles * 5 + remainder * 1; // 1+1+3 = 5 per 3 attacks
            if (remainder >= 1) total_damage += 0; // first remainder attacks are 1
            if (remainder >= 2) total_damage += 0; // second remainder attack is 1
            // Alternatively, total_damage = 2*full_cycles (for the two 1's) + 3*full_cycles (for the 3) + remainder * 1
            total_damage = 2 * full_cycles + 3 * full_cycles + remainder;
            total_damage = (mid / 3) * 5 + (mid % 3) * 1;
            // Wait, no. The pattern is 1,1,3,1,1,3,... for t starting at T+1.
            // So for k attacks, each three attacks deal 5 damage.
            ll damage = (mid / 3) * 5;
            if (mid % 3 == 1) damage += 1;
            else if (mid % 3 == 2) damage += 2;
            
            if (damage >= hi) {
                high = mid - 1;
                k = mid;
            } else {
                low = mid + 1;
            }
        }
        T += k;
    }
    cout << T << endl;
    return 0;
}