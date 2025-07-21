#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> H(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> H[i];
    }

    long long T = 0;

    while (true) {
        bool all_zero = true;
        for (int i = 0; i < N; ++i) {
            if (H[i] > 0) {
                all_zero = false;
                break;
            }
        }
        if (all_zero) break;

        ++T;
        if (T % 3 == 0) {
            for (int i = 0; i < N; ++i) {
                if (H[i] > 0) {
                    --H[i];
                }
            }
        } else {
            for (int i = 0; i < N; ++i) {
                if (H[i] > 0) {
                    --H[i];
                }
            }
        }
    }

    std::cout << T << std::endl;
    return 0;
}