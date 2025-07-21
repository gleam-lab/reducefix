#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    int n;
    std::cin >> n;

    long double x = 0, y = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        long double nx, ny;
        std::cin >> nx >> ny;

        ans += std::hypot(nx - x, ny - y);
        x = nx, y = ny;
    }

    ans += std::hypot(x, y); // Return trip to the origin

    std::cout << std::fixed << std::setprecision(10) << ans << std::endl;
    return 0;
}