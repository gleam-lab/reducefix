#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    long long T = 0;
    long long bonus_attack = 0; // Number of remaining bonus attacks (3-damage attacks not yet used)

    for (int i = 0; i < N; ++i) {
        // First, apply any bonus attacks from previous enemies
        long long use_bonus = min(bonus_attack, H[i] / 3 + (H[i] % 3 != 0));
        H[i] -= use_bonus * 3;
        T += use_bonus;
        bonus_attack -= use_bonus;

        // If enemy is still alive, we need to attack it with normal hits
        if (H[i] > 0) {
            // Calculate how many attacks needed: each cycle of 3 turns gives one bonus attack
            long long cycles = H[i] / 5;
            long long rem = H[i] % 5;

            T += cycles * 3;

            if (rem > 0) {
                T += 1;
                if (rem >= 3) {
                    bonus_attack += 1; // One more bonus attack available
                }
            }
        } else {
            // No need to advance time for this step
            if (bonus_attack > 0) {
                bonus_attack -= 1;
                if (bonus_attack > 0) bonus_attack = 0;
            }
        }
    }

    cout << T << endl;
    return 0;
}