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
    long long bonus3 = 0, bonus1 = 0;

    for (int i = 0; i < N; ++i) {
        long long h = H[i];

        // Total attacks needed: each big attack (3 damage) or small attack (1 damage)
        // We simulate how many attacks of each type are needed

        long long total_attacks = 0;
        long long attacks3 = 0;
        long long attacks1 = 0;

        // First use as many triple attacks as possible
        attacks3 = h / 3;
        h -= attacks3 * 3;

        // Then finish with single attacks if needed
        attacks1 = h;

        total_attacks = attacks3 + attacks1;

        // Now we need to determine how many of the upcoming T values
        // will hit a multiple of 3 (which gives 3 damage), and how many will be 1-damage

        // We maintain a counter for how many attacks until next triple attack (T % 3 == 0)
        // That is, we track current position in the 3-cycle: [normal, normal, triple]

        // We calculate how many of the next 'total_attacks' will fall on T%3==0

        long long cycle_count = total_attacks / 3;
        long long rem = total_attacks % 3;

        long long hits_on_triple = cycle_count; // one triple per 3 attacks

        // Check remaining attacks after full cycles
        // Starting from current position in the 3-cycle
        for (int j = 0; j < rem; ++j) {
            if ((T + j) % 3 == 2) { // T+1 would make it multiple of 3
                hits_on_triple++;
            }
        }

        // So the number of triple attacks we can actually do is hits_on_triple
        // The rest must be done as single attacks

        T += total_attacks;
    }

    cout << T << endl;
    return 0;
}