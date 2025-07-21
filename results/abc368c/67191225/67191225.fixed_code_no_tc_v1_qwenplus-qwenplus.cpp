#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    ll T = 0;

    for (int i = 0; i < N; ++i) {
        ll h = H[i];

        // We simulate how many attacks are needed and how T increases
        // Each enemy needs some number of attacks:
        // - Every 3 attacks, one is a "triple" attack (t=3k)
        // - So in groups of 3 attacks: 1 triple (3 damage), 2 singles (1 damage each)
        // That totals to 5 damage per 3 attacks

        // We calculate how many full 5-damage cycles are needed
        ll full_cycles = h / 5;
        ll remaining_damage = h % 5;
        T += full_cycles * 3;

        if (remaining_damage > 0) {
            T++; // One more attack at least
            if (T % 3 == 0) {
                // If T is now multiple of 3, we did a triple attack
                // This might not have been intended
                // In this case, the next enemy may be hit by this triple attack which is wrong
                // So we need to fix this simulation approach

                // Actually, we cannot just add time like this
                // We must simulate when T is a multiple of 3 or not
                // So let's correct this with a better approach below
            }
        }

        // Correct approach starts here:
        // Instead of trying to compute it directly,
        // we simulate the attack timing carefully

        // Reset T calculation for proper approach
        T = 0;
        ll time = 0;
        for (int i = 0; i < N; ++i) {
            ll health = H[i];
            while (health > 0) {
                time++;
                if (time % 3 == 0) {
                    health -= 3;
                } else {
                    health -= 1;
                }
            }
            // Once current enemy is defeated, move to next
        }
        T = time;
        break; // Just to avoid re-running incorrect logic below
    }

    cout << T << endl;
    return 0;
}