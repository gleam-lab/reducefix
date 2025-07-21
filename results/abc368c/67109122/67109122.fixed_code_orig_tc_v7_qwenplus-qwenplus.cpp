#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    long long T = 0;

    for (int i = 0; i < N; ++i) {
        // Determine how many full 3-attack cycles (with 5 damage total) can be done
        long long full_cycles = H[i] / 5;
        T += full_cycles * 3;
        H[i] -= full_cycles * 5;

        // Handle remaining health with individual attacks
        while (H[i] > 0) {
            if ((T % 3) == 0) {
                H[i] -= 3;
            } else {
                H[i] -= 1;
            }
            ++T;
        }
    }

    cout << T << endl;
    return 0;
}