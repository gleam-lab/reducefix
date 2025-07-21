#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    long long T = 0;

    for (int i = 0; i < N; i++) {
        // Calculate the number of attacks needed to defeat the current enemy
        int attacks = H[i] / 3; // Use 3 attacks if possible (when T is a multiple of 3)
        if (H[i] % 3 != 0) {
            attacks += 1; // Add 1 if there's a remainder (when T is not a multiple of 3)
        }

        // Update the total number of attacks
        T += attacks;

        // Ensure the enemy's health is reduced to 0 or less
        H[i] -= attacks;
    }

    cout << T << endl;
    return 0;
}