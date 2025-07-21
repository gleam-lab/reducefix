#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> H(N);
    for(int i = 0; i < N; ++i) {
        std::cin >> H[i];
    }

    long long T = 0;
    while(true) {
        bool any_alive = false;
        for(int i = 0; i < N; ++i) {
            if(H[i] > 0) {
                any_alive = true;
                break;
            }
        }
        if(!any_alive) break;

        ++T;
        for(int i = 0; i < N; ++i) {
            if(H[i] > 0) {
                if(T % 3 == 0) H[i] -= 3;
                else H[i] -= 1;
                break;
            }
        }
    }

    std::cout << T << std::endl;
    return 0;
}