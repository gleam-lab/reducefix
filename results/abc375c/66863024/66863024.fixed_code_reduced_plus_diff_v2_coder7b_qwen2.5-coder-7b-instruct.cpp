#include <iostream>
#include <vector>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::vector<std::pair<long long, long long>> points(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> points[i].first >> points[i].second;
    }

    long double cost = 0;
    for (size_t i = 0; i < points.size(); ++i) {
        if (i > 0) {
            long double dx = points[i].first - points[i - 1].first;
            long double dy = points[i].second - points[i - 1].second;
            cost += std::hypot(dx, dy);
        }
    }

    // Return to the origin
    if (n > 0) {
        long double dx = points.back().first;
        long double dy = points.back().second;
        cost += std::hypot(dx, dy);
    }

    std::cout.precision(15);
    std::cout << cost << '\n';

    return 0;
}