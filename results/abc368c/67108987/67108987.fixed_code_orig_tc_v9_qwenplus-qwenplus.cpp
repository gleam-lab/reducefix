#include <bits/stdc++.h>
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

    // We will simulate the attack process efficiently
    long long T = 0;

    // We'll use a priority queue to always attack the frontmost enemy with health > 0
    int idx = 0;
    while (idx < N && H[idx] == 0) idx++;

    // To simulate attacks on the frontmost enemy, we don't need a priority queue.
    // Instead, we simulate each round and determine how many attacks are needed
    // to kill the current enemy before moving to the next.

    for (int i = 0; i < N; ++i) {
        if (H[i] == 0) continue;

        // Determine number of full cycles (3 attacks: two 1-damage, one 3-damage)
        // Each cycle deals total 5 damage
        long long full_cycles = H[i] / 5;
        long long remaining = H[i] % 5;

        T += full_cycles * 3;

        if (remaining > 0) {
            T += 1;
            remaining -= 1; // first attack is always 1 damage
        }
        if (remaining > 0) {
            T += 1;
            remaining -= 1;
        }
        if (remaining > 0) {
            T += 1;
            remaining -= 3;
        }
    }

    cout << T << endl;
    return 0;
}