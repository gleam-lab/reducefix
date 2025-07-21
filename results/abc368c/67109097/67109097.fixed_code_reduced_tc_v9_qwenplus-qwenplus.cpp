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
        // Each attack on this enemy will be either 1 or 3 damage
        // We need to determine how many attacks of each type are needed

        // Let x = number of 3-damage attacks
        // Let y = number of 1-damage attacks
        // Then we want: 3x + y >= H[i]
        // And minimize total attacks = x + y
        // Since we can only use 3-damage attacks at T % 3 == 0, they must come every 3 steps

        // This means we're effectively solving:
        // Find minimum T such that the number of 3s in the first T steps is x and total damage >= H[i]

        // Binary search on T
        long long low = 0, high = 2 * H[i]; // Upper bound estimate
        while (low < high) {
            long long mid = (low + high) / 2;
            // In first 'mid' steps, number of 3-damage attacks = floor(mid / 3)
            // Total damage = 3 * floor(mid / 3) + mid % 3
            long long threeAttacks = mid / 3;
            long long oneAttacks = mid % 3;
            long long damage = 3 * threeAttacks + oneAttacks;
            
            if (damage >= H[i]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        // The minimal T needed for this enemy
        long long enemyT = low;
        
        // Apply this T to our global timeline
        T += enemyT;
    }

    cout << T << endl;
    return 0;
}