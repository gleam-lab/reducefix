#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    double curX = 0, curY = 0;
    double total = 0;  // Changed to double for higher precision

    for (int i = 0; i < N; ++i) {
        long long x, y;
        std::cin >> x >> y;

        double dx = curX - x;
        double dy = curY - y;
        total += std::sqrt(dx * dx + dy * dy);  // Corrected calculation using sqrt

        curX = x;
        curY = y;
    }

    total += std::sqrt(curX * curX + curY * curY);  // Corrected calculation using sqrt

    // Print with high precision
    std::cout << std::fixed << std::setprecision(20) << total << '\n';

    return 0;
}