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
        // Number of full triplets (each consisting of 3 attacks: two -1 and one -3 at T%3 == 0)
        long long full_cycles = H[i] / 5;
        T += full_cycles * 3;
        H[i] -= full_cycles * 5;

        if (H[i] > 0) {
            // One more attack sequence needed
            T += 1;
            H[i] -= 1; // first attack is always T not multiple of 3 => -1
            if (H[i] > 0) {
                T += 1;
                H[i] -= 1; // second attack same logic
            }
            if (H[i] > 0) {
                T += 1;
                H[i] -= 3; // third attack is at T%3 == 0 => -3
            }
        }
    }

    cout << T << endl;
    return 0;
}