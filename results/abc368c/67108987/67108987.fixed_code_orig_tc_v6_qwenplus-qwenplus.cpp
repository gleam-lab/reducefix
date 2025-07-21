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
        // For each enemy, calculate how many full cycles of 3 attacks are needed
        long long full_cycles = (H[i] + 4) / 5;  // Ceiling division to ensure coverage
        T += full_cycles * 3;
        
        // No need to track remaining health since we simulate only attack count
    }

    cout << T << endl;
    return 0;
}