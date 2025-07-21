#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    long long x = 0, y = 0;
    double total_cost = 0.0;

    for (int i = 0; i < N; ++i) {
        long long new_x, new_y;
        std::cin >> new_x >> new_y;

        // Calculate Euclidean distance using long long to prevent overflow
        double dx = static_cast<double>(new_x - x);
        double dy = static_cast<double>(new_y - y);
        double segment_cost = std::sqrt(dx * dx + dy * dy);

        total_cost += segment_cost;
        x = new_x;
        y = new_y;
    }

    // Return to origin
    double return_cost = std::sqrt(x * x + y * y);
    total_cost += return_cost;

    // Print result with high precision
    std::cout << std::fixed << std::setprecision(10) << total_cost << std::endl;

    return 0;
}