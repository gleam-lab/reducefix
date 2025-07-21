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
        ll h = H[i];

        // We simulate how many total attacks are needed
        // Each group of 3 attacks deals 1+1+3 = 5 damage
        ll fullGroups = h / 5;
        T += fullGroups * 3;
        ll remaining = h % 5;

        if (remaining > 0) {
            // Need to do additional attacks based on remainder
            T++;

            // Check the current T modulo 3 to know what kind of attack we're starting with
            ll mod = T % 3;
            remaining -= (mod == 0 ? 3 : 1);

            if (remaining > 0) {
                T++;
                mod = (mod + 1) % 3;
                remaining -= (mod == 0 ? 3 : 1);

                if (remaining > 0) {
                    T++;
                }
            }
        }
    }

    cout << T << endl;
    return 0;
}