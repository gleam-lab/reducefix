#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    int N;
    std::cin >> N;

    long long x = 0, y = 0;
    long long sum = 0;

    for(int i = 0; i < N; ++i) {
        long long dx, dy;
        std::cin >> dx >> dy;
        sum += std::abs(dx - x) + std::abs(dy - y);
        x = dx;
        y = dy;
    }

    // Add the distance back to the origin
    sum += std::abs(x) + std::abs(y);

    // Print with high precision
    std::cout << std::fixed << std::setprecision(15) << sum / 2.0 << std::endl;

    return 0;
}