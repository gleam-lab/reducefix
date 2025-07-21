#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    long long T = 0;
    for (int i = 0; i < N; ++i) {
        // Determine how much damage the current enemy receives at each step
        // Each cycle of 3 attacks delivers: 3 + 1 + 1 = 5 damage
        long long full_cycles = H[i] / 5;
        long long remaining_health = H[i] % 5;

        if (full_cycles > 0) {
            T += full_cycles * 3;
            // These attacks are fully absorbed by this enemy
        }

        // Handle remaining health
        if (remaining_health > 0) {
            // We may need to attack this enemy one or two more times
            if (T % 3 == 0) {
                // Next attack is triple damage
                if (remaining_health <= 3) {
                    T += 1;
                } else {
                    // Need at least 2 attacks
                    T += 2;
                }
            } else {
                // Next attack is single damage
                if (remaining_health == 1) {
                    T += 1;
                } else if (remaining_health == 2) {
                    T += 2;
                } else { // remaining_health == 3 or 4
                    // After this single damage, still need another attack
                    T += 1;
                    if (T % 3 == 0) {
                        // If next attack is triple, that finishes it
                    } else {
                        // Otherwise need one more attack
                        T += 1;
                    }
                }
            }
        }
    }

    cout << T << endl;
    return 0;
}