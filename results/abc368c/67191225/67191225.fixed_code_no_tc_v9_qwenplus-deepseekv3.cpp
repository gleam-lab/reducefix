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
        // The attacks are periodic with period 3: 1, 1, 3, 1, 1, 3, ...
        // We can find the number of full cycles (each cycle reduces health by 5 in 3 attacks)
        ll cycles = h / 5;
        ll remaining = h % 5;
        T += cycles * 3;
        h = remaining;
        
        if (h > 0) {
            if (T % 3 == 2) {
                // Next attack is 3, which can finish the remaining health if >= 3
                if (h <= 3) {
                    T += 1;
                } else {
                    T += 3;
                }
            } else {
                // Next attacks are 1 or 1, then 3
                if (h == 1) {
                    T += 1;
                } else if (h == 2) {
                    T += 2;
                } else if (h == 3) {
                    if (T % 3 == 0) {
                        T += 3;
                    } else {
                        T += 2;
                    }
                } else if (h == 4) {
                    if (T % 3 == 0) {
                        T += 3;
                    } else {
                        T += 3;
                    }
                }
            }
        }
    }

    cout << T << endl;
    return 0;
}