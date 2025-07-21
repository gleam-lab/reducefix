#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<std::pair<long long, long long>> points(n);
    long long px = 0, py = 0;
    long double ans = 0;
    
    for(int i = 0; i < n; ++i) {
        std::cin >> points[i].first >> points[i].second;
    }
    
    for(int i = 0; i < n; ++i) {
        long long dx = points[i].first - px;
        long long dy = points[i].second - py;
        ans += std::hypotl(dx, dy);
        px = points[i].first;
        py = points[i].second;
    }
    
    // Return to origin
    long long dx = px;
    long long dy = py;
    ans += std::hypotl(dx, dy);
    
    std::cout << std::fixed << std::setprecision(10) << ans << '\n';
    return 0;
}