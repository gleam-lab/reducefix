#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    long long T = 0;
    for (int i = 0; i < N; i++) {
        // While current enemy is still alive
        while (H[i] > 0) {
            T++;
            if (T % 3 == 0) {
                H[i] -= 3;
            } else {
                H[i] -= 1;
            }
            // If enemy is defeated, move to next
            if (H[i] <= 0) break;

            // Skip attacks on dead enemies at the front
            int j = i;
            while (j < N && H[j] <= 0) j++;
            if (j > i) {
                // We've advanced past some defeated enemies
                // But we must simulate each T increment
                T += (j - i);
                i = j - 1; // will be incremented to j in loop
                break;
            }
        }
    }

    cout << T << endl;
    return 0;
}