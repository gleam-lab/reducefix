#include <iostream>
#include <vector>
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
        // Determine how many attacks are needed to defeat this enemy
        ll h = H[i];
        
        // We simulate the attack pattern: two 1-damage attacks followed by one 3-damage attack
        // This is equivalent to a cycle of 3 attacks doing 5 damage total
        // We need to calculate how many full cycles and extra attacks are needed
        
        // Full cycles of 3 attacks (each cycle deals 5 damage)
        ll full_cycles = h / 5;
        T += full_cycles * 3;
        h -= full_cycles * 5;

        // Now handle remaining health (0-4)
        if (h > 0) {
            // At most 2 attacks needed after full cycles
            if (T % 3 == 0) {
                // If T is multiple of 3, next attack is triple damage
                if (h >= 3) {
                    T++;
                } else {
                    T += h; // Need normal attacks
                }
            } else {
                // Need to check when we can use triple damage
                bool used_triple = false;
                for (ll attack_count = 1; attack_count <= 2; ++attack_count) {
                    if ((T + attack_count) % 3 == 0) {
                        // This would be a triple attack
                        if (h <= 3) {
                            T += attack_count;
                            used_triple = true;
                            break;
                        }
                    }
                }
                if (!used_triple) {
                    T += (h + 1) / 2; // Worst case: only single damage attacks
                }
            }
        }
    }

    cout << T << endl;
    return 0;
}