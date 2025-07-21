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
        // Determine how many attacks are needed to reduce H[i] to <=0
        // Each attack is:
        // - at time t % 3 == 0 => damage 3
        // - else => damage 1

        // Let’s simulate the number of attacks required using a greedy approach:
        // Every 3 attacks, we can do 3 + 1 + 1 = 5 damage total
        // So full cycles of 3 attacks: full_cycles = H[i] / 5
        // Remaining damage = H[i] % 5
        // Then determine additional attacks based on remaining damage

        long long full_cycles = H[i] / 5;
        long long remainder = H[i] % 5;

        T += full_cycles * 3;

        if (remainder > 0) {
            // After full cycles, apply minimal attacks to finish off the enemy
            // For remainder from 1 to 4:
            // - If remainder <= 2: need 'remainder' attacks of 1 damage each
            // - If remainder == 3: one attack of 3 damage
            // - If remainder == 4: one attack of 3, then one of 1 → 2 attacks
            if (remainder == 4) {
                T += 2;
            } else {
                T += (remainder + 2) / 3; // ceil(remainder / 3)
            }
        }
    }

    cout << T << endl;
    return 0;
}