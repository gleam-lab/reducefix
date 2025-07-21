#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    // Initialize variables with high precision
    long double cost = 0;
    long double ans = 0;
    long double nowX = 0, nowY = 0;
    long double nextX, nextY;

    for(int i = 0; i < n; ++i) {
        std::cin >> nextX >> nextY;

        // Calculate Euclidean distance using long double for precision
        cost = std::sqrtl(std::powl(nextX - nowX, 2.0L) + std::powl(nextY - nowY, 2.0L));

        // Update current position
        nowX = nextX;
        nowY = nextY;

        // Accumulate total cost
        ans += cost;
    }

    // Return to the origin
    cost = std::sqrtl(std::powl(nowX, 2.0L) + std::powl(nowY, 2.0L));
    ans += cost;

    // Print the result with sufficient precision
    std::cout << std::fixed << std::setprecision(15) << ans << std::endl;

    return 0;
}