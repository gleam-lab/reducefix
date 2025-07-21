#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    // We simulate the process efficiently:
    // - Ticks increase by 1 each round.
    // - At every tick, only the frontmost enemy with health > 0 can be attacked.
    // - Every 3 ticks, a triple damage is applied (3), otherwise single (1).

    long long T = 0;
    for (int i = 0; i < N; ++i) {
        if (H[i] == 0) continue;

        // For each enemy, we determine how many attacks it needs to die.
        // Each attack at positions 3k+1 and 3k+2 deals 1 damage,
        // and attack at position 3k+3 deals 3 damage.

        // Let’s model the number of full cycles of 3 attacks: each cycle does 5 damage (1 + 1 + 3)
        long long full_cycles = H[i] / 5;
        long long remaining_health = H[i] % 5;

        T += full_cycles * 3;

        // Apply damage from full cycles to this and future enemies
        if (remaining_health > 0) {
            // Simulate the next 1-3 attacks until this enemy dies
            while (remaining_health > 0) {
                T++;
                if (T % 3 == 0) {
                    remaining_health -= 3;
                } else {
                    remaining_health -= 1;
                }
            }
        }

        // Since this enemy is now dead, propagate any overflow damage to later enemies
        // No need to do anything explicitly as per problem logic — we move to next enemy
    }

    cout << T << endl;
    return 0;
}