#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    int n;
    std::cin >> n;

    double px = 0, py = 0;
    double ans = 0;
    
    for (int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        ans += std::hypot(x - px, y - py);
        px = x;
        py = y;
    }

    ans += std::hypot(px, py);
    
    std::cout << std::fixed << std::setprecision(10) << ans << std::endl;
    return 0;
}