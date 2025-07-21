#include <bits/stdc++.h>

int main() {
    long double cost = 0;
    long double ans = 0;
    int operation;
    int nowX = 0, nowY = 0;
    int nextX, nextY;

    std::cin >> operation;

    for (int i = 0; i < operation; ++i) {
        std::cin >> nextX >> nextY;

        // Calculate the Euclidean distance squared to avoid computing square roots multiple times
        long double dx = nowX - nextX;
        long double dy = nowY - nextY;
        cost = dx * dx + dy * dy;

        // Update current position
        nowX = nextX;
        nowY = nextY;

        // Add the cost to the total answer
        ans += std::sqrtl(cost);
    }

    // Calculate the cost back to the origin
    long double dx = nowX - 0;
    long double dy = nowY - 0;
    cost = dx * dx + dy * dy;
    ans += std::sqrtl(cost);

    std::cout << ans << std::endl;

    return 0;
}