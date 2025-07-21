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
    long long pos = 0; // Position in the 3-step cycle (0, 1, 2)

    for (long long h : H) {
        // Determine how many full 3-attack cycles are needed
        long long cycle_attacks = h / 5;
        T += cycle_attacks * 3;

        long long rem = h % 5;

        if (rem == 0) {
            // No additional attacks needed
            pos = 0;
        } else if (rem <= 2) {
            // Need small attacks at end of cycle
            if (pos + rem > 3) {
                // Wrap around to next cycle
                T += 3;
                pos = (pos + rem) % 3;
            } else {
                T += rem;
                pos += rem;
                if (pos >= 3) {
                    T += 3;
                    pos = 0;
                }
            }
        } else { // rem == 3 or 4
            // Need big attack(s)
            if (pos == 0) {
                T += 3;
                pos = 0;
            } else {
                T += (3 - pos + 3);
                pos = 0;
            }
            if (rem == 4) {
                T += 2;
                pos = 2;
            }
        }
    }

    cout << T << endl;
    return 0;
}