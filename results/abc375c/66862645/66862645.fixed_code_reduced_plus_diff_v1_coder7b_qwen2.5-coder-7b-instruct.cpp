#include <iostream>
#include <cmath>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> X(N);
    std::vector<int> Y(N);

    for (int i = 0; i < N; ++i) {
        std::cin >> X[i] >> Y[i];
    }

    double totalCost = 0;

    // Calculate the cost of moving from the origin to the first point
    totalCost += std::sqrt(X[0] * X[0] + Y[0] * Y[0]);

    // Calculate the cost of moving from each point to the next
    for (int i = 0; i < N - 1; ++i) {
        totalCost += std::sqrt((X[i] - X[i + 1]) * (X[i] - X[i + 1]) + 
                               (Y[i] - Y[i + 1]) * (Y[i] - Y[i + 1]));
    }

    // Calculate the cost of moving from the last point back to the origin
    totalCost += std::sqrt(X[N - 1] * X[N - 1] + Y[N - 1] * Y[N - 1]);

    std::cout << totalCost << std::endl;

    return 0;
}