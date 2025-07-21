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
        ll full_cycles = h / 5;
        T += full_cycles * 3;
        ll rem = h % 5;

        if (rem == 0) continue;

        // Determine how many extra attacks are needed depending on current T mod 3
        ll t_mod = T % 3;
        if (t_mod == 0) {
            // Next attacks are: 1 (T+1), 1 (T+2), 3 (T+3)
            if (rem <= 2) {
                T += rem;
            } else {
                T += 3 + (rem - 2);
            }
        } else if (t_mod == 1) {
            // Next attacks are: 1 (T+1), 3 (T+2), 1 (T+3)
            if (rem == 1) {
                T += 1;
            } else if (rem == 2) {
                T += 2;
            } else {
                T += 3 + (rem - 3);
            }
        } else { // t_mod == 2
            // Next attacks are: 3 (T+1), 1 (T+2), 1 (T+3)
            if (rem <= 3) {
                T += 1;
            } else {
                T += 1 + (rem - 3);
            }
        }
    }

    cout << T << endl;
}