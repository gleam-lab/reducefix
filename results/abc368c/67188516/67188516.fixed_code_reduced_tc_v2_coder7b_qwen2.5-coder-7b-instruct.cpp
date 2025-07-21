#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> H(N);
    for(int i = 0; i < N; ++i) {
        std::cin >> H[i];
    }

    long long total_time = 0;

    for(int i = 0; i < N; ++i) {
        if(H[i] > 0) {
            if(H[i] % 3 == 0) {
                total_time += H[i] / 3;
            } else {
                total_time += H[i] / 3 + 1;
            }
        }
    }

    std::cout << total_time << std::endl;

    return 0;
}