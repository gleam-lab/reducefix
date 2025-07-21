#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    int n;
    cin >> n;
    vector<int> health(n);
    for (int i = 0; i < n; ++i) {
        cin >> health[i];
    }

    long long T = 0; // Initialize the number of actions T
    int i = 0; // Start from the first enemy
    while (i < n) {
        if (T % 3 == 0) {
            // When T is a multiple of 3, attack in batches of 3
            int nextMultipleOf3 = (T / 3 + 1) * 3; // Next multiple of 3 after T
            int remainingTillMultipleOf3 = nextMultipleOf3 - T; // Actions left to reach the next multiple of 3

            while (remainingTillMultipleOf3 > 0 && i < n && health[i] > 0) {
                health[i] -= 3;
                T++;
                remainingTillMultipleOf3--;
                // If the enemy's health becomes zero or less, move to the next enemy
                if (health[i] <= 0) {
                    i++;
                }
            }

            // If we are at a multiple of 3 and still have enemies left, do one more action
            if (health[i] > 0) {
                health[i]--;
                T++;
                i++;
            }
        } else {
            // When T is not a multiple of 3, attack one enemy at a time
            while (i < n && health[i] > 0) {
                health[i]--;
                T++;
                // If the enemy's health becomes zero or less, move to the next enemy
                if (health[i] <= 0) {
                    i++;
                }
            }
        }
    }

    cout << T << endl;
    return 0;
}