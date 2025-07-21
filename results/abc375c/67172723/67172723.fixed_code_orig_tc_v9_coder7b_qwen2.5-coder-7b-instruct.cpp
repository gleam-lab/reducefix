#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false); // Fast I/O operations
    std::cin.tie(nullptr);

    long long n;
    std::cin >> n;

    std::vector<std::pair<long long, long long>> points(n);
    for(long long i = 0; i < n; ++i) {
        std::cin >> points[i].first >> points[i].second;
    }

    double total_cost = 0;
    for(long long i = 0; i < n - 1; ++i) {
        total_cost += std::hypot(points[i].first - points[i + 1].first, points[i].second - points[i + 1].second);
    }

    // Adding the cost of returning to the origin
    total_cost += std::hypot(points[n - 1].first, points[n - 1].second);

    // Set precision to meet the required accuracy
    std::cout << std::fixed << std::setprecision(10) << total_cost << '\n';

    return 0;
}