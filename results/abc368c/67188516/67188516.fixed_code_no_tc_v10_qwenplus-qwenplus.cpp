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
    long long bonus_count = 0; // Counts how many triple damage attacks we can use

    for (int i = 0; i < N; ++i) {
        // Apply previously saved triple damage attacks first if possible
        long long used_bonus = min(bonus_count, H[i] / 3);
        H[i] -= used_bonus * 3;
        bonus_count -= used_bonus;
        T += used_bonus;

        // Now process remaining health
        long long attacks = H[i]; // Each attack does at least 1 damage
        long long full_cycles = attacks / 3;
        long long remaining = attacks % 3;

        T += full_cycles * 3;
        bonus_count += full_cycles;

        // Handle the remaining 0-2 damage needed
        if (remaining == 1) {
            T++;
            bonus_count++;
        } else if (remaining == 2) {
            T += 2;
            bonus_count += 2;
        }
    }

    cout << T << endl;
    return 0;
}