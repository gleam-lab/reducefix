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

    // We'll process enemies from front to back
    for (int i = 0; i < N; ++i) {
        // How many full cycles of 3 attacks we can do on this enemy
        long long full_cycles = H[i] / 5;
        if (full_cycles > 0) {
            T += full_cycles * 3;
            H[i] -= full_cycles * 5;
        }

        // If still some health left, we need to simulate the remaining attacks
        if (H[i] > 0) {
            // We need to apply attacks one by one until health <= 0
            // and update both T and H[i]
            while (H[i] > 0) {
                T++;
                if (T % 3 == 0) {
                    H[i] -= 3;
                } else {
                    H[i] -= 1;
                }
            }
        }
    }

    cout << T << endl;
    return 0;
}