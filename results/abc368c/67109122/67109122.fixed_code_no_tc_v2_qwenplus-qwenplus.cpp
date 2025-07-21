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
        // Determine how many full attacks of value 5 (3+1+1) we can apply
        long long full_cycles = H[i] / 5;
        long long remaining = H[i] % 5;

        T += full_cycles * 3;

        if (remaining > 0) {
            if (T % 3 == 0) {
                // If T is a multiple of 3, we get to use the 3-damage attack right now
                T += 1;
                remaining -= 3;
                if (remaining > 0) {
                    T += 2; // Two more single-damage attacks
                }
            } else {
                // We have to wait until T becomes a multiple of 3
                long long wait = (3 - (T % 3));
                T += wait;
                T += 1; // Use the 3-damage attack
                remaining -= 3;
                if (remaining > 0) {
                    T += 2; // Two more single-damage attacks
                }
            }
        }
    }

    cout << T << endl;
    return 0;
}