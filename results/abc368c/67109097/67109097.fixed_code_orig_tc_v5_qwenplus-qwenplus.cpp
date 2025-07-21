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
        // How many full cycles of 3 seconds where 5 damage is dealt
        long long full_cycles = H[i] / 5;
        long long rem_damage = H[i] % 5;

        T += full_cycles * 3;

        if (rem_damage > 0) {
            // Check how many extra steps are needed after full cycles
            // At T+1, T+2, ..., check if T % 3 == 0 => 3 damage else 1
            for (int j = 0; j < 3 && rem_damage > 0; ++j) {
                T++;
                if (T % 3 == 0) {
                    rem_damage -= 3;
                } else {
                    rem_damage -= 1;
                }
            }
        }
    }

    cout << T << endl;
    return 0;
}