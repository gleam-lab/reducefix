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
        // Full cycles of 3 attacks: two 1-damage, one 3-damage => total damage 5
        long long full_cycles = H[i] / 5;
        H[i] %= 5;

        T += full_cycles * 3;

        // Handle remaining damage manually
        while (H[i] > 0) {
            if (T % 3 == 0)
                H[i] -= 3;
            else
                H[i] -= 1;
            ++T;
        }
    }

    cout << T << "\n";
    return 0;
}