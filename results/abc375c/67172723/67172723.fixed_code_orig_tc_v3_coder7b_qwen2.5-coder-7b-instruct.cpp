#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<std::pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> points[i].first >> points[i].second;
    }

    double ans = 0;
    int px = 0, py = 0;
    for (const auto& p : points) {
        ans += std::hypot(px - p.first, py - p.second);
        px = p.first;
        py = p.second;
    }
    ans += std::hypot(px, py);

    std::cout << std::fixed << std::setprecision(15) << ans << '\n';
    return 0;
}