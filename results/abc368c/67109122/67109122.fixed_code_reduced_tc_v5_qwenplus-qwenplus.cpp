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
        // Determine how many full attack cycles we can do on this enemy
        // Each cycle is 3 attacks: two -1 and one -3, total damage = 5
        long long full_cycles = H[i] / 5;
        long long remaining_health = H[i] % 5;

        // Add time for full cycles
        T += full_cycles * 3;

        // Apply damage from full cycles
        H[i] -= full_cycles * 5;

        // Now handle remaining health with individual attacks
        while (H[i] > 0) {
            T++;
            if (T % 3 == 0) {
                H[i] -= 3;
            } else {
                H[i] -= 1;
            }
        }
    }

    cout << T << endl;
    return 0;
}