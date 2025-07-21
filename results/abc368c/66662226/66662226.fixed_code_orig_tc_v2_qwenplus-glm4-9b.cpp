#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> healths(n);
    long long total_attacks = 0;

    for (int i = 0; i < n; ++i) {
        std::cin >> healths[i];
        while (healths[i] > 0) {
            if (total_attacks % 3 == 0) {
                healths[i] -= 3;
            } else {
                healths[i]--;
            }
            total_attacks++;
        }
    }

    std::cout << total_attacks << std::endl;
}