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
        // Calculate the number of full triple attacks (3,1,1 pattern)
        ll full_cycles = h / 5;
        ll remaining = h % 5;
        T += 3 * full_cycles;
        remaining -= full_cycles; // Each full cycle contributes 1 to the remaining due to the pattern
        if (remaining > 0) {
            if (T % 3 == 0) {
                // Next attack is a triple attack
                remaining -= 3;
                T += 1;
                if (remaining > 0) {
                    T += remaining;
                }
            } else {
                // Next attacks are single until T+1 mod 3 is 0 or remaining is 0
                ll steps = (3 - (T % 3)) % 3;
                if (steps >= remaining) {
                    T += remaining;
                } else {
                    T += steps;
                    remaining -= steps;
                    if (remaining > 0) {
                        T += 1;
                        remaining -= 3;
                        if (remaining > 0) {
                            T += remaining;
                        }
                    }
                }
            }
        }
    }

    cout << T << endl;
    return 0;
}