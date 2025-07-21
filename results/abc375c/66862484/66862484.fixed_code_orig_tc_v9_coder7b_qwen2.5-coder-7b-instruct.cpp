#include <iostream>
#include <cmath>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    double curX = 0, curY = 0;   // Current position (origin)
    double total = 0;             // Total cost

    for (int i = 0; i < N; ++i) {
        double x, y;
        std::cin >> x >> y;

        double dx = curX - x;
        double dy = curY - y;
        total += std::sqrt(dx * dx + dy * dy);  // Calculate Euclidean distance with sqrt

        curX = x; 
        curY = y;
    }

    // Return to the origin from the last point
    total += std::sqrt(curX * curX + curY * curY);

    // Print the total cost with high precision
    std::cout << std::fixed << std::setprecision(15) << total << '\n';

    return 0;
}