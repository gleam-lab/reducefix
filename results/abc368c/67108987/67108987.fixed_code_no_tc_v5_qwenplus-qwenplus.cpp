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
        // Determine how many attacks are needed to eliminate current enemy
        long long h = H[i];
        
        // Each 3 attacks deal 5 damage total (1 + 1 + 3)
        long long fullCycles = h / 5;
        long long remaining = h % 5;

        T += fullCycles * 3;

        if (remaining > 0) {
            T += 1; // First attack: -1
            remaining -= 1;
        }
        if (remaining > 0) {
            T += 1; // Second attack: -1
            remaining -= 1;
        }
        if (remaining > 0) {
            T += 1; // Third attack: -3
        }
    }

    cout << T << endl;
    return 0;
}