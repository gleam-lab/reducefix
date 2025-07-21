#include <iostream>
#include <vector>

long long calculateTotalAttacks(const std::vector<long long>& healths) {
    long long total_attacks = 0;
    for (long long health : healths) {
        while (health > 0) {
            total_attacks++;
            if (total_attacks % 3 == 0) {
                health -= 3;
            } else {
                health -= 1;
            }
        }
    }
    return total_attacks;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> healths(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> healths[i];
    }
    
    long long total_attacks = calculateTotalAttacks(healths);
    std::cout << total_attacks << std::endl;
    
    return 0;
}