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
        // Calculate full cycles (3 attacks: 1+1+3 = 5 damage)
        ll full_cycles = h / 5;
        T += 3 * full_cycles;
        h -= full_cycles * 5;

        // Process remaining attacks
        while (h > 0) {
            T += 1;
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