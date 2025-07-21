#include <iostream>
#include <vector>
#include <cmath>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<long long> X(N), Y(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> X[i] >> Y[i];
    }

    double total_distance = 0.0;

    // Calculate the distance from the origin to the first point
    total_distance += std::sqrt(X[0] * X[0] + Y[0] * Y[0]);

    // Calculate the distance between consecutive points
    for (int i = 0; i < N - 1; ++i) {
        total_distance += std::sqrt((X[i + 1] - X[i]) * (X[i + 1] - X[i]) + (Y[i + 1] - Y[i]) * (Y[i + 1] - Y[i]));
    }

    // Calculate the distance from the last point back to the origin
    total_distance += std::sqrt(X[N - 1] * X[N - 1] + Y[N - 1] * Y[N - 1]);

    // Print the total distance with 16 decimal places
    std::cout << std::fixed << std::setprecision(16) << total_distance << '\n';

    return 0;
}