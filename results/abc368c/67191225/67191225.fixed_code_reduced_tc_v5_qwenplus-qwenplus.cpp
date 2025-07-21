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
        ll rem = h % 5;

        T += full_cycles * 3;

        if (rem > 0) {
            T += 1;
            if (rem >= 3) {
                // Can use triple attack in current T step (already incremented)
                if (T % 3 == 0) {
                    // Already aligned with triple attack
                } else {
                    T++;
                    if (T % 3 != 0) T++;
                }
            } else {
                T += rem - 1;
            }
        }
    }

    cout << T << endl;
}