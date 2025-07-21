#include <iostream>
#include <cmath>
#include <vector>

int main() {
    long long N;
    std::cin >> N;

    if (N == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::vector<long long> X(N), Y(N);
    for (long long i = 0; i < N; ++i) {
        std::cin >> X[i] >> Y[i];
    }

    long double x = 0, y = 0, total_cost = 0;

    for (long long i = 0; i < N; ++i) {
        long double dx = X[i] - x;
        long double dy = Y[i] - y;
        total_cost += std::sqrt(dx * dx + dy * dy);
        x = X[i];
        y = Y[i];
    }

    // Return to origin
    long double dx = x - 0;
    long double dy = y - 0;
    total_cost += std::sqrt(dx * dx + dy * dy);

    std::cout << total_cost << std::endl;

    return 0;
}