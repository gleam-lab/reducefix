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
        // Calculate how many full attack cycles we can perform on this enemy
        long long full_cycles = H[i] / 5;
        long long remaining_health = H[i] % 5;

        // Each full cycle (3 attacks: 1, 1, 3) takes 3 seconds and removes 5 health
        T += full_cycles * 3;
        
        // Now handle the remaining health
        while (remaining_health > 0) {
            if (T % 3 == 0) {
                remaining_health -= 3;
            } else {
                remaining_health -= 1;
            }
            T++;
        }
    }

    cout << T << endl;
    return 0;
}