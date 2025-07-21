#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    long long T = 0;
    for (int i = 0; i < N; i++) {
        // Calculate the number of full attacks needed for each enemy
        int full_attacks = H[i] / 3;
        // Add full attacks to T
        T += full_attacks;
        // Subtract the health that is reduced by full attacks
        H[i] -= full_attacks * 3;
        // Calculate the remaining attacks needed for the leftover health
        if (H[i] > 0) {
            T += H[i];  // Each remaining health point needs an additional attack
        }
    }
    cout << T << endl;
    return 0;
}