#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> H(N);
    long long T = 0;

    for (int i = 0; i < N; ++i) {
        std::cin >> H[i];
        while (H[i] > 0) {
            if (T % 3 == 0) {
                H[i] -= 3;
            } else {
                H[i]--;
            }
            T++;
        }
    }

    std::cout << T << std::endl;
    return 0;
}