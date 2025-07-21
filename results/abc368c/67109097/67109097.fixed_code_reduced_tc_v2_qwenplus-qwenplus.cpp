#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];

    long long T = 0;

    for (int i = 0; i < N; i++) {
        // Determine number of attacks needed to kill this enemy
        // Each attack sequence is: -1, -1, -3 (total -5 over 3 turns)
        // So every full cycle reduces health by 5
        long long h = H[i];
        long long full_cycles = h / 5;
        long long remainder = h % 5;

        T += full_cycles * 3;

        // Handle the remaining damage
        if (remainder > 0) {
            if (T % 3 == 0) {
                // At T divisible by 3, next triple attack would be now
                // We can use that to deal 3 damage
                if (remainder >= 3) {
                    T += 1;
                    remainder -= 3;
                } else {
                    // Still need to do 1-damage attacks
                    T += remainder;
                    remainder = 0;
                }
            } else {
                // Calculate how many single attacks until next triple attack
                long long steps_to_triple = 3 - (T % 3);
                if (steps_to_triple <= remainder) {
                    T += steps_to_triple;
                    remainder -= steps_to_triple;
                } else {
                    // Finish with single attacks
                    T += remainder;
                    remainder = 0;
                }
            }

            // If we still have remainder after using triple attack if applicable
            while (remainder > 0) {
                T++;
                if (T % 3 == 0) {
                    remainder -= 3;
                } else {
                    remainder -= 1;
                }
            }
        }
    }

    cout << T << endl;
    return 0;
}