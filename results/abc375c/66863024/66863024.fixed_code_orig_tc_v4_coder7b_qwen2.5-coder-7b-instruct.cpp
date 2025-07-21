#include <iostream>
#include <vector>
#include <cmath>

int main() {
    long long n;
    std::cin >> n;

    std::vector<std::pair<long long, long long>> points(n);
    for(long long i = 0; i < n; ++i){
        std::cin >> points[i].first >> points[i].second;
    }

    // Starting from origin (0,0)
    long double x = 0, y = 0;
    long double total_cost = 0;

    for(const auto& point : points) {
        long double dx = point.first - x;
        long double dy = point.second - y;
        total_cost += std::sqrt(dx*dx + dy*dy);
        x = point.first;
        y = point.second;
    }

    // Return to origin
    long double dx = 0 - x;
    long double dy = 0 - y;
    total_cost += std::sqrt(dx*dx + dy*dy);

    std::cout << std::fixed << std::setprecision(15) << total_cost << std::endl;

    return 0;
}