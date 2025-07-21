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
        ll start_T = T;

        if (remaining > 0) {
            if (start_T % 3 == 2) {
                // Next attack is T+1, which is a multiple of 3 (3 damage)
                if (remaining <= 3) {
                    T += 1;
                } else {
                    T += 3;
                }
            } else {
                // Next attacks are 1 or more 1-damage attacks followed by a 3-damage attack if needed
                if (remaining <= (3 - (start_T % 3))) {
                    T += remaining;
                } else {
                    T += (3 - (start_T % 3)) + 1;
                }
            }
        }
    }

    cout << T << endl;
    return 0;
}