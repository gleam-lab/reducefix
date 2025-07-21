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
        // Determine how many full attack cycles are needed
        long long full_cycles = H[i] / 5;
        T += full_cycles * 3;
        H[i] -= full_cycles * 5;

        if (H[i] > 0) {
            T += 1;
            H[i] -= 1;
        }
        if (H[i] > 0) {
            T += 1;
            H[i] -= 1;
        }
        if (H[i] > 0) {
            T += 1;
            H[i] -= 3;
        }
    }

    cout << T << endl;
    return 0;
}