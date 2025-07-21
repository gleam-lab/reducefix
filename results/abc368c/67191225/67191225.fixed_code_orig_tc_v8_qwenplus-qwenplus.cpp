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
        // Calculate how many attacks are needed to reduce this enemy to 0
        ll h = H[i];
        ll cycle3 = h / 5;  // Each 3 turns, we get 2 hits of 1 and one hit of 3 -> total 5 damage
        ll rem = h % 5;

        T += cycle3 * 3;

        if (rem > 0) {
            T += 1;
            if (T % 3 == 0) {
                // On triple attack turn - deals 3 damage
                if (rem > 3) {
                    T += 1;
                }
            } else {
                // On regular attack turn - deals 1 damage
                rem -= 1;
                if (rem > 0) {
                    T += 1;
                    if (T % 3 == 0) {
                        if (rem > 2) {
                            T += 1;
                        }
                    } else {
                        rem -= 1;
                        if (rem > 0) {
                            T += 1;
                        }
                    }
                }
            }
        }
    }

    cout << T << endl;
    return 0;
}