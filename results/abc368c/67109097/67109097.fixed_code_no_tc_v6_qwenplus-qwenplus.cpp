#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    long long T = 0;

    for (int i = 0; i < N; ++i) {
        // We simulate the attack on the current enemy until its health is <= 0
        long long h = H[i];

        // Every 3 attacks, we deal 3 damage once, otherwise 1 damage per attack
        // So in a group of 3 time units, we can do 5 damage total (3 + 1 + 1)
        // We calculate how many full groups of 3 attacks are needed
        long long full_cycles = h / 5;
        T += full_cycles * 3;

        long long remaining = h % 5;

        // After full cycles, apply remaining attacks one by one
        while (remaining > 0) {
            if ((T + 1) % 3 == 0) {
                remaining -= 3;
            } else {
                remaining -= 1;
            }
            T++;
        }
    }

    cout << T << endl;
    return 0;
}