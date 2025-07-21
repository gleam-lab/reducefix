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

    for (int i = 0; i < N; ++i) {
        // Each group of 3 attacks: two 1-damage and one 3-damage (total 5 damage)
        long long full_cycles = H[i] / 5;
        T += full_cycles * 3;

        long long remaining_health = H[i] % 5;

        if (remaining_health > 0) {
            T += 1;
            remaining_health -= 1;
        }
        if (remaining_health > 0) {
            T += 1;
            remaining_health -= 1;
        }
        if (remaining_health > 0) {
            T += 1;
            remaining_health -= 3;
        }
    }

    cout << T << endl;

    return 0;
}