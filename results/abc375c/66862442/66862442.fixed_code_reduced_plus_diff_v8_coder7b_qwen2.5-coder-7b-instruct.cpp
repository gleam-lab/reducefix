#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    double curX = 0.0, curY = 0.0;
    double total = 0.0;

    for (int i = 0; i < N; ++i) {
        long long x, y;
        std::cin >> x >> y;

        double dx = curX - x;
        double dy = curY - y;
        total += std::sqrt(dx * dx + dy * dy);

        curX = x; 
        curY = y;
    }

    // Return to the origin
    double dx = curX - 0.0;
    double dy = curY - 0.0;
    total += std::sqrt(dx * dx + dy * dy);

    // Print the result with high precision
    std::cout << std::fixed << std::setprecision(10) << total << '\n';

    return 0;
}