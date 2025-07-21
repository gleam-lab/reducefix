#include <iostream>
#include <cmath>
#include <iomanip>

void solve() {
    int n;
    double x = 0, y = 0, t = 0;
    std::cin >> n;
    while (n--) {
        double a, b;
        std::cin >> a >> b;
        t += std::sqrt((x - a) * (x - a) + (y - b) * (y - b));
        x = a;
        y = b;
    }
    t += std::sqrt(x * x + y * y);
    std::cout << std::setprecision(20) << t << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
    std::cout << std::endl;
    return 0;
}