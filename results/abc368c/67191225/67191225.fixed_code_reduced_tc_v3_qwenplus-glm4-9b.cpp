#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int &h : H) {
        cin >> h;
    }

    // Strategy: Calculate the minimum number of attacks T required to defeat all enemies.
    // Since every third attack deals 3 damage, we calculate how many times we can use this
    // and then adjust for the remaining damage.

    // For each enemy, calculate the number of full 3-damage attacks it can take
    int T = 0;
    for (int health : H) {
        int full3Attacks = health / 3;
        T += full3Attacks;
        // Remaining health after full 3-damage attacks
        int remainingHealth = health % 3;
        if (remainingHealth > 0) {
            // If remaining health is 1, we need one more attack if T is not a multiple of 3
            // If remaining health is 2, we need to check if the next attack is a multiple of 3
            // If it's not, we need two more attacks (one for health and one to adjust the turn count)
            if (remainingHealth == 1) {
                if (T % 3 != 0) {
                    T += 1; // This accounts for the attack and the fact that we can't end on a multiple of 3
                }
            } else if (remainingHealth == 2) {
                if (T % 3 == 1) {
                    T += 2; // Two attacks to make it a multiple of 3
                } else {
                    T += 1; // One attack, but we're already on a multiple of 3
                }
            }
        }
    }

    cout << T << endl;
    return 0;
}