#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

double calculateDistance(const std::pair<double, double>& p1, const std::pair<double, double>& p2) {
    return std::sqrt(std::pow(p1.first - p2.first, 2) + std::pow(p1.second - p2.second, 2));
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::pair<double, double>> points(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> points[i].first >> points[i].second;
    }

    double totalCost = 0.0;
    for (size_t i = 1; i < points.size(); ++i) {
        totalCost += calculateDistance(points[i - 1], points[i]);
    }

    // Adding the distance from the last point back to the origin
    totalCost += calculateDistance(points.back(), {0.0, 0.0});

    std::cout << std::fixed << std::setprecision(20) << totalCost << std::endl;

    return 0;
}