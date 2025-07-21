#include <iostream>
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;

    ll T = 0; // Initialize attack count
    for (ll i = 0; i < N; ++i) {
        ll H;
        cin >> H;

        // Calculate the number of full cycles of 3 attacks
        ll full_cycles = H / 3;
        T += full_cycles * 3; // Each full cycle requires 3 attacks

        // Calculate remaining health after all full cycles
        H %= 3;

        // Perform the remaining attacks needed
        while (H > 0) {
            if (T % 3 == 0) {
                // If T is a multiple of 3, attack pattern is 3, 1, 2, 3, ...
                // Since T is a multiple of 3, the next attack will decrease health by 3
                T++;
            } else {
                // Otherwise, attack pattern is 1, 2, 3, 1, 2, 3, ...
                // Decrease health by 1
                H--;
            }
            T++;
        }
    }

    cout << T << endl;
    return 0;
}