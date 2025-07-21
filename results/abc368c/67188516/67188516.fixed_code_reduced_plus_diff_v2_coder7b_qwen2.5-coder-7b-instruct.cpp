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
        for (int& h : H) {
            if (h > 0) {
                all_zero = false;
                break;
            }
        }
        if (all_zero) {
            break;
        }

        ++T;
        for (int& h : H) {
            if (h > 0) {
                if (T % 3 == 0) {
                    h -= 3;
                } else {
                    --h;
                }
            }
        }
    }

    std::cout << T << std::endl;
    return 0;
}