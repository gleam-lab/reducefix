#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
   cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];

    long long T = 0;
    int i = 0;
    while (i < N) {
        // Calculate how many full attacks we can make on this enemy
        int full_attacks = H[i] / 3;
        // Decrease the health by the full attacks
        H[i] -= full_attacks * 3;
        // Increase T for each full attack
        T += full_attacks;

        // Handle the remainder of the health after full attacks
        if (H[i] > 0) {
            T += 1;
            if (T % 3 == 0) {
                // If T is a multiple of 3, we attack by 3
                if (H[i] >= 3) {
                    H[i] -= 3;
                } else {
                    H[i] = 0;  // If health is less than 3 and T is a multiple of 3, we finish the enemy
                }
            } else {
                // Otherwise, we attack by 1
                H[i]--;
            }
        }
        i++;  // Move to the next enemy
    }
    cout << T << endl;
    return 0;
}