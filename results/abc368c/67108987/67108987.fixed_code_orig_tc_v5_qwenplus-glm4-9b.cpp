#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    long long T = 0;
    long long fullSets = 0;

    // Calculate the number of full 3-time attacks and the number of times T needs to be increased by 1
    for (int i = 0; i < N; i++) {
        int health = H[i];
        int fullAttacks = health / 3;
        fullSets += fullAttacks;
        health -= fullAttacks * 3;

        if (health > 0) {
            T += 1; // Add 1 to T if there's any remaining health that couldn't be fully attacked by full sets
            health -= 1; // Reduce health by 1 as T is increased by 1

            // If health is still more than 0 after reducing by 1, we need one more attack (not a multiple of 3)
            if (health > 0) {
                T += 1;
            }
        }
    }

    // Since each full set contributes 3 to T, we multiply the number of full sets by 3
    T += fullSets * 3;

    cout << T << endl;
    return 0;
}