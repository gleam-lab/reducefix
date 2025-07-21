#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

int main() {
    int N;
    std::cin >> N;
    std::vector<ll> H(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> H[i];
    }

    ll T = 0;
    for (int i = 0; i < N; ++i) {
        // We simulate the process of attacking this enemy until its health is <= 0
        while (H[i] > 0) {
            ++T;
            if (T % 3 == 0) {
                H[i] -= 3;
            } else {
                H[i]--;
            }
        }
    }

    std::cout << T << "\n";
    return 0;
}