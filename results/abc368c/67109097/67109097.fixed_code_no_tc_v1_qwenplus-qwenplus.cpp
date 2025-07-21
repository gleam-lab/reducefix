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
        // Number of full triplets of attacks (3 attacks: two 1-damage and one 3-damage)
        long long full_cycles = H[i] / 5;
        T += full_cycles * 3;
        long long remaining_health = H[i] % 5;

        // Handle remaining health with individual attacks
        if (remaining_health > 0) {
            // Try to use optimal combination:
            // If remaining_health == 4, we can do 1 (T+1), 1 (T+1), 3 (T+1) => total 3 attacks
            // If remaining_health == 5, already handled above
            // In general, it takes at most 3 attacks to finish off remaining_health <= 4
            T += (remaining_health + 2) / 3;
        }
    }

    cout << T << endl;
    return 0;
}