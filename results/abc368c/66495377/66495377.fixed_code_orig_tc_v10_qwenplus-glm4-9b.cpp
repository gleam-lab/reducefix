#include <iostream>
#include <vector>

long long solve(const std::vector<int>& healths) {
    long long attacks = 0;
    long long current_attacks = 0;
    
    for (int health : healths) {
        if (health % 3 == 0) {
            // If the health is exactly divisible by 3, use 3 attacks.
            attacks += health / 3;
            current_attacks += health / 3;
        } else {
            // Otherwise, use multiple of 3 attacks, then 1 extra attack.
            attacks += (health / 3) + 1;
            current_attacks = (health / 3) + 1;
        }
        
        // Simulate incrementing T until the next attack
        while (current_attacks < 3) {
            attacks += 1;
            current_attacks += 1;
        }
        
        // If we've reached the end of the row of enemies, no need to simulate further.
        if (health == 0) break;
    }
    
    return attacks;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> healths(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> healths[i];
    }
    
    std::cout << solve(healths) << std::endl;
    
    return 0;
}