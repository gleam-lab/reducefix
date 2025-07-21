#include <iostream>
#include <vector>

long long calculateDamage(long long health, bool isMultipleOfThree) {
    if (isMultipleOfThree) {
        return health / 3;
    } else {
        return health;
    }
}

long long solve(std::vector<int>& enemies) {
    long long totalAttacks = 0;
    for (auto& h : enemies) {
        long long attacks = 0;
        while (h > 0) {
            attacks++;
            h -= calculateDamage(h, (attacks + 1) % 3 == 0);
        }
        totalAttacks += attacks;
    }
    return totalAttacks;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> enemies(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> enemies[i];
    }
    
    std::cout << solve(enemies) << std::endl;
    return 0;
}