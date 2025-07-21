#include <iostream>
#include <cmath>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> points(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> points[i].first >> points[i].second;
    }

    double total_cost = 0.0;
    int x = 0, y = 0;

    for (const auto& point : points) {
        int dx = point.first - x;
        int dy = point.second - y;
        total_cost += std::hypot(dx, dy);
        x = point.first;
        y = point.second;
    }

    total_cost += std::hypot(x, y);

    std::cout.precision(15);
    std::cout << total_cost << std::endl;

    return 0;
}