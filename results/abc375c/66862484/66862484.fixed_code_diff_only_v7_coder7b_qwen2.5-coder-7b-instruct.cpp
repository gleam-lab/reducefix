#include <iostream>
#include <cmath>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    double curX = 0, curY = 0;  // Current position (origin)
    double total = 0;           // Total cost

    for (int i = 0; i < N; ++i) {
        long long x, y;
        std::cin >> x >> y;

        double dx = curX - x;
        double dy = curY - y;
        total += std::sqrt(dx * dx + dy * dy);  // Calculate Euclidean distance

        curX = x;
        curY = y;
    }

    // Return to the origin from the last point
    total += std::sqrt(curX * curX + curY * curY);

    // Output the result with precision up to 6 decimal places
    std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    std::cout.precision(6);
    std::cout << total << '\n';

    return 0;
}