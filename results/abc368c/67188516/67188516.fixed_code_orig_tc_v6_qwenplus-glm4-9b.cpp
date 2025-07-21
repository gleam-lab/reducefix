#include <iostream>
#include <vector>
#include <climits>

int main() {
    int N;
    std::cin >> N;

    long long healths[N];
    long long currentT = 0;
    for (int i = 0; i < N; ++i) {
        std::cin >> healths[i];
        long long enemyT = (healths[i] + 2) / 3; // +2 to floor when dividing by 3
        if (enemyT < currentT) {
            // Too many attacks, go back in time
            currentT = enemyT;
        } else {
            currentT = enemyT;
        }
    }

    std::cout << currentT << std::endl;

    return 0;
}