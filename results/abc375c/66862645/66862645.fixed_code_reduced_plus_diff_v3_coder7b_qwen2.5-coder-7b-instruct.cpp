#include <iostream>
#include <cmath>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> points[i].first >> points[i].second;
    }

    double cost = 0;
    int x = 0, y = 0;

    for (const auto& point : points) {
        cost += std::sqrt(std::pow(point.first - x, 2) + std::pow(point.second - y, 2));
        x = point.first;
        y = point.second;
    }

    cost += std::sqrt(x * x + y * y); // Return to origin

    std::cout << cost << std::endl;

    return 0;
}