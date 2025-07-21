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
        // Determine how many full triplets of attacks (3 attacks) we need
        // Each triplet consists of:
        // - One attack at T%3 == 0 (does 3 damage)
        // - Two attacks at T%3 != 0 (do 1 damage each)
        // Total damage per triplet: 5

        long long fullTriplets = H[i] / 5;
        long long remaining = H[i] % 5;

        T += fullTriplets * 3;

        // Handle remaining damage after full triplets
        if (remaining > 0) {
            // Check the current T modulo 3 to determine when the next 3-damage attack will happen
            int mod = T % 3;
            if (mod == 0) {
                // We can do 3-damage attack now
                T += 1;
                remaining -= 3;
                if (remaining <= 0) {}
                else if (remaining <= 1) {
                    T += 1;
                    remaining -= 1;
                } else { // remaining == 2
                    T += 2;
                    remaining -= 2;
                }
            } else if (mod == 1) {
                // First do a 1-damage attack
                T += 1;
                remaining -= 1;
                if (remaining <= 0) {}
                else if (remaining <= 2) {
                    T += 1;
                    remaining -= 1; // still 1 left
                    T += 1;
                    remaining -= 1;
                } else { // remaining == 3
                    T += 1;
                    remaining -= 1;
                    T += 1;
                    remaining -= 1;
                    T += 1;
                    remaining -= 3;
                }
            } else { // mod == 2
                // First two attacks are 1-damage, then 3-damage
                T += 2;
                remaining -= 2;
                if (remaining <= 0) {}
                else {
                    T += 1;
                    remaining -= 3;
                }
            }
        }
    }

    cout << T << endl;
    return 0;
}