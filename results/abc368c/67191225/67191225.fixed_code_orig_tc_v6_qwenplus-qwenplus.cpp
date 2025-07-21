#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<ll> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    ll T = 0;
    for (int i = 0; i < N; ++i) {
        // Compute how many full cycles of 3 attacks are needed
        ll full_cycles = H[i] / 5;
        T += full_cycles * 3;

        ll rem = H[i] % 5;

        if (rem > 0) {
            T += 1;
            if (T % 3 == 0 && rem >= 3) {
                rem -= 3;
            } else if (T % 3 != 0 && rem >= 1) {
                rem -= 1;
            }

            if (rem > 0) {
                // We need one more attack to finish the enemy
                T += 1;
                if (T % 3 == 0) {
                    rem -= 3;
                } else {
                    rem -= 1;
                }
            }

            if (rem > 0) {
                // One last attack
                T += 1;
                if (T % 3 == 0) {
                    rem -= 3;
                } else {
                    rem -= 1;
                }
            }
        }
    }

    cout << T << endl;
    return 0;
}