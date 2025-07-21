#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    int n;
    std::cin >> n;
    
    long double x = 0, y = 0, prev_x = 0, prev_y = 0;
    long double total_cost = 0;

    for (int i = 0; i < n; ++i) {
        std::cin >> prev_x >> prev_y;
        total_cost += std::hypot(prev_x - x, prev_y - y);
        x = prev_x;
        y = prev_y;
    }

    // Add the cost of returning to the origin
    total_cost += std::hypot(x, y);

    std::cout << std::fixed << std::setprecision(15) << total_cost << std::endl;
    return 0;
}