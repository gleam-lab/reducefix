#include <bits/stdc++.h>
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
        // Calculate how many full cycles of 3 attacks (5 damage) fit into h
        ll full_cycles = h / 5;
        ll remaining = h % 5;
        ll additional_attacks = 0;
        if (remaining > 0) {
            // Simulate the remaining attacks to find how many more attacks are needed
            ll temp_T = T + 3 * full_cycles;
            while (remaining > 0) {
                temp_T++;
                if (temp_T % 3 == 0) {
                    remaining -= 3;
                } else {
                    remaining -= 1;
                }
                additional_attacks++;
            }
        }
        T += 3 * full_cycles + additional_attacks;
    }

    cout << T << endl;
    return 0;
}