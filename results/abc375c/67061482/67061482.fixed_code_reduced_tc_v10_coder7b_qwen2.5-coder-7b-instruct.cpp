#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false); // Fast I/O
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    long long x = 0, y = 0;
    long long total_cost = 0;

    for(int i = 0; i < N; ++i) {
        long long xi, yi;
        std::cin >> xi >> yi;
        
        // Calculate the distance from current position to the next point
        long long dx = xi - x;
        long long dy = yi - y;
        total_cost += static_cast<long long>(std::sqrt(dx * dx + dy * dy));

        // Update current position
        x = xi;
        y = yi;
    }

    // Return to the origin
    total_cost += static_cast<long long>(std::sqrt(x * x + y * y));

    // Print the result with high precision
    std::cout << std::fixed << std::setprecision(15) << total_cost / 1e6 << std::endl;

    return 0;
}