#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    ll T = 0;
    for (int i = 0; i < N; ++i) {
        // Calculate how many attacks are needed to reduce current enemy to 0 or less
        ll h = H[i];
        
        // We simulate the attack pattern on this enemy:
        // Every 3rd attack does 3 damage, others do 1 damage
        // So in a full cycle of 3 attacks: total damage = 3 + 1 + 1 = 5
        ll full_cycles = h / 5;
        ll remaining_damage = h % 5;
        
        // Each full cycle takes 3 time units
        T += full_cycles * 3;
        
        if (remaining_damage > 0) {
            // After full cycles, we need 1 or 2 more attacks depending on remaining damage
            // Determine when the next attack on this enemy would fall in the T timeline
            ll base_T = T;
            
            // Try possible additional attacks
            if (remaining_damage == 1 || remaining_damage == 2 || remaining_damage == 3) {
                T++;
            } else if (remaining_damage == 4) {
                T += 2;
            }
        }
    }

    cout << T << endl;
    return 0;
}