#include <iostream>
#include <vector>
#include <algorithm>

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
        if (h <= 0) continue;

        // Calculate the number of full triplets (3 attacks) needed
        ll full_cycles = h / 5;
        ll remaining = h % 5;

        // The full_cycles contribute 3 * full_cycles to T (since each triplet is 3 attacks)
        T += 3 * full_cycles;
        h -= 5 * full_cycles;

        // Now handle the remaining health
        while (h > 0) {
            T++;
            if (T % 3 == 0) {
                h -= 3;
            } else {
                h -= 1;
            }
        }
    }
    cout << T << endl;
    return 0;
}