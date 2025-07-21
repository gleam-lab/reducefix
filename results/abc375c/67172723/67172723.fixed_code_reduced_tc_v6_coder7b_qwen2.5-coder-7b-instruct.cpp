#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    int n;
    std::cin >> n;
    
    long long px = 0, py = 0;
    double ans = 0;
    long long x, y;
    for(int i = 0; i < n; ++i) {
        std::cin >> x >> y;
        ans += std::hypot(px - x, py - y);
        px = x;
        py = y;
    }
    
    ans += std::hypot(px, py);
    std::cout << std::fixed << std::setprecision(10) << ans << '\n';
    return 0;
}