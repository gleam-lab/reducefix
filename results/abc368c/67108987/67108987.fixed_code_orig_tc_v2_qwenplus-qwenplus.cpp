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
        // Each enemy is processed independently due to frontmost constraint

        // We need to determine how many attacks of each type are needed:
        // Every 3 seconds: one attack at T%3 == 0 (does 3 damage)
        // The other two attacks do 1 damage each

        // Let's find out how many full cycles of 3 attacks we can do,
        // and what the remainder is.

        // One cycle: 5 damage total (3 + 1 + 1)
        long long full_cycles = H[i] / 5;
        long long remaining = H[i] % 5;

        T += full_cycles * 3;

        if (remaining > 0) {
            T += 1; // attack with 1 damage
            remaining -= 1;
        }
        if (remaining > 0) {
            T += 1; // attack with 1 damage
            remaining -= 1;
        }
        if (remaining > 0) {
            T += 1; // attack with 3 damage
        }
    }

    cout << T << endl;
    return 0;
}