#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> H(N);
    for(int i = 0; i < N; i++) {
        std::cin >> H[i];
    }

    int T = 0;
    while(true) {
        bool changed = false;
        for(int i = 0; i < N; i++) {
            if(H[i] > 0) {
                T++;
                H[i]--;
                if(T % 3 == 0) {
                    H[i]--;
                }
                changed = true;
            }
        }
        if(!changed) break;
    }

    std::cout << T << std::endl;
    return 0;
}