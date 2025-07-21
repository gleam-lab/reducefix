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

    long long T = 0;
    // We'll simulate attacks in batches using math instead of step-by-step

    // Each enemy needs to be attacked until its health becomes <= 0
    // Each attack at T+1, T+2, ..., depending on whether T is multiple of 3

    // To model this efficiently, precompute how many total hits needed per enemy
    // and track the timing accordingly.

    // We use a priority queue to simulate time-efficient attack scheduling
    // where we always attack the first enemy with remaining HP > 0

    // We can treat each enemy in sequence because they're attacked in order

    for (int i = 0; i < N; ++i) {
        long long hp = H[i];

        if (hp <= 0) continue;

        // Determine how many attacks are needed to deplete this enemy
        // We simulate the timing of attacks starting from T+1 onward

        // Each group of 3 attacks consists of 2x1 + 1x3 = 5 damage
        // So each such "cycle" reduces health by 5 and takes 3 turns

        long long cycles = hp / 5;
        long long rem = hp % 5;

        T += cycles * 3;

        // Now apply the remaining damage
        while (rem > 0) {
            T++;
            if (T % 3 == 0)
                rem -= 3;
            else
                rem -= 1;
        }
    }

    cout << T << '\n';

    return 0;
}