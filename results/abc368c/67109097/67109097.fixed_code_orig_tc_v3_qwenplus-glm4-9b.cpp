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
    for (int i = 0; i < N; ++i) {
        // Total damage needed for this enemy
        int damage_needed = H[i];
        
        // Reduce the damage by full 3-damage attacks
        damage_needed -= (damage_needed / 3) * 3;
        
        // Reduce the damage by full 1-damage attacks
        damage_needed -= (damage_needed / 1) * 1;
        
        // Accumulate the total number of attacks
        T += damage_needed;
        
        // Adjust the total damage for the next enemy
        H[i] -= damage_needed;
    }

    std::cout << T << std::endl;
    return 0;
}