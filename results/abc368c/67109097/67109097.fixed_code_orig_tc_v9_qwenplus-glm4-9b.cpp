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
    for (int health : H) {
        // Full attacks to defeat the enemy
        T += health / 3;
        // Additional attacks if health is not a multiple of 3
        T += (health % 3 > 0) ? 1 : 0;
    }
    
    std::cout << T << std::endl;
    return 0;
}