#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<long long> H(N);
    
    for (int i = 0; i < N; ++i) {
        std::cin >> H[i];
    }

    long long T = 0;
    bool lastMultipleOf3 = false;

    for (int i = 0; i < N; ++i) {
        if (H[i] % 3 == 0) {
            T += H[i] / 3;
        } else {
            T += (H[i] / 3) + 1;
            lastMultipleOf3 = true;
        }
        if (lastMultipleOf3 && H[i] % 3 != 0) {
            T++;
            lastMultipleOf3 = false;
        }
    }

    std::cout << T << std::endl;
    return 0;
}