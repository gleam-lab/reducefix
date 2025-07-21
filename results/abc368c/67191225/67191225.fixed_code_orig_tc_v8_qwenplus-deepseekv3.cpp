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
        ll full_cycles = H[i] / 5;
        ll remaining = H[i] % 5;
        T += full_cycles * 3;
        ll base_T = T;

        if (remaining > 0) {
            if (base_T % 3 == 0) {
                // Next attack is 3 damage
                if (remaining <= 3) {
                    T += 1;
                } else {
                    T += 2;
                }
            } else if (base_T % 3 == 1) {
                // Next attack is 1 damage
                if (remaining <= 1) {
                    T += 1;
                } else if (remaining <= 2) {
                    T += 2;
                } else {
                    T += 3;
                }
            } else { // base_T % 3 == 2
                // Next attack is 1 damage
                if (remaining <= 1) {
                    T += 1;
                } else if (remaining <= 3) {
                    T += 2;
                } else {
                    T += 3;
                }
            }
        }
    }

    cout << T << endl;
    return 0;
}