#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n;
    long long x = 0, y = 0;
    double c = 0;

    std::cin >> n;
    
    // Using vector to store points instead of array for dynamic memory management
    std::vector<std::pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> points[i].first >> points[i].second;
    }

    // Loop through each point and calculate the distance to the next one
    for (int i = 0; i < n; ++i) {
        c += std::sqrt(std::pow(points[i].first - x, 2) + std::pow(points[i].second - y, 2));
        x = points[i].first;
        y = points[i].second;
    }

    // Add the distance back to the origin
    c += std::sqrt(x * x + y * y);

    // Print the result with precision
    std::cout << std::fixed << std::setprecision(10) << c << std::endl;

    return 0;
}