#include <iostream>
#include <vector>

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
        ll remaining = H[i];
        // The attack pattern is 1, 1, 3, 1, 1, 3, etc.
        // Each full cycle (three attacks) deals 5 damage.
        ll full_cycles = remaining / 5;
        T += full_cycles * 3;
        remaining -= full_cycles * 5;
        // Now handle the remaining health after full cycles
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