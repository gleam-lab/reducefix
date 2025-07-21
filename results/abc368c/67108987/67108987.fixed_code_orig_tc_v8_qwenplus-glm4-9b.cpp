#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N + 9);
    for (int i = 1; i <= N; i++) cin >> H[i];
    long long T = 0;

    for (int i = 1; i <= N; i++) {
        // Calculate the number of times we can subtract 5 health points from the enemy
        long long a = H[i] / 5;
        T += a * 3; // Each time we subtract 5, we use 3 attacks, so add 3 * a to T
        H[i] -= a * 5; // Subtract 5 * a health points from the enemy

        // If there is still health left after the multiples of 5 attacks
        if (H[i] > 0) {
            T += 1; // Add 1 to T for the attack
            H[i] -= 1; // Subtract 1 health point from the enemy
        }
    }

    cout << T << endl;
    return 0;
}