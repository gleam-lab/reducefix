#include <iostream>
#include <vector>
#include <cmath>

using ll = long long;

int main() {
    int N;
    std::cin >> N;
    std::vector<ll> H(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> H[i];
    }

    ll T = 0;
    for (int i = 0; i < N; ++i) {
        // For each enemy, determine how many attacks are needed
        ll h = H[i];
        
        // We need to simulate attacks until the health is <= 0
        // Each second attack does 1 damage, and every third attack does 3 damage
        // This pattern repeats every 3 ticks: damage sequence is [1,1,3]
        
        // Total damage per cycle of 3 seconds = 5
        ll full_cycles = h / 5;
        T += full_cycles * 3;
        ll remaining = h % 5;

        // Now handle remaining damage depending on current time T
        if (remaining > 0) {
            T++;
            if (T % 3 == 0) {
                if (remaining >= 3) T++;
            } else {
                if (remaining > 1) T++;
            }
        }
    }

    std::cout << T << std::endl;
    return 0;
}