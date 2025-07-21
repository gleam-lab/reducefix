#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    long long T = 0;
    for (int i = 0; i < N; i++) {
        long long h = H[i];
        // Calculate the number of 3-damage attacks (every 3rd attack)
        long long full_cycles = h / (3 + 1 + 1); // One cycle is 3 attacks dealing 5 damage (3 + 1 + 1)
        long long remaining = h % (3 + 1 + 1);
        // The above might not be accurate, so better to compute it differently
        // Each sequence of 3 attacks deals 5 damage (3 + 1 + 1)
        long long damage_per_3_attacks = 5;
        long long num_3_attack_cycles = h / damage_per_3_attacks;
        T += num_3_attack_cycles * 3;
        remaining = h - num_3_attack_cycles * damage_per_3_attacks;
        // Now handle the remaining damage
        while (remaining > 0) {
            T++;
            if (T % 3 == 0) {
                remaining -= 3;
            } else {
                remaining -= 1;
            }
        }
    }
    cout << T << endl;
    return 0;
}