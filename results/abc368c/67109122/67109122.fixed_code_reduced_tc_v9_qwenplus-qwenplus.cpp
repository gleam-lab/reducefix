#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N + 1);
    for (int i = 1; i <= N; i++) cin >> H[i];

    long long T = 0;
    for (int i = 1; i <= N; ++i) {
        // Calculate how many full attack cycles we can apply on this enemy
        // Each cycle consists of:
        // - Time t: T+1 -> T+3
        // - Attacks: 1 (T+1), 1 (T+2), 3 (T+3)
        // So total damage per cycle = 5
        long long full_cycles = H[i] / 5;
        long long remainder = H[i] % 5;

        T += full_cycles * 3;

        // Handle remaining health after full cycles
        if (remainder > 0) {
            // Simulate the next few attacks needed
            if (T % 3 == 0) {
                // If current T is multiple of 3, then next 3 attacks will be at T+1 (not multiple), T+2 (not), T+3 (yes)
                // So one strong attack available
                if (remainder >= 3) {
                    T += 3;  // All 3 attacks
                } else {
                    // We need to decide whether it's better to wait for a triple attack or just use small ones
                    T += remainder;  // Just use simple attacks
                }
            } else {
                // Current time not multiple of 3
                // Determine how many steps to next triple attack
                long long steps_to_triple = 3 - (T % 3); // steps until we get T%3 == 0

                if (steps_to_triple < 3 && remainder >= 3) {
                    // We can reach a triple attack and have enough damage left for meaningful use
                    T += steps_to_triple;
                    remainder -= 3;
                    T += (remainder + 2); // ceil(remainder / 1.0)
                } else {
                    // Better to just attack normally
                    T += remainder;
                }
            }
        }
    }

    cout << T << endl;
    return 0;
}