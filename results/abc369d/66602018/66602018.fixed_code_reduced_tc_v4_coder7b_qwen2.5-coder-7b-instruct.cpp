#include <iostream>
#include <algorithm>
#include <climits>

#define INF LLONG_MIN

int main() {
    int n;
    long long dp0 = 0, dp1 = INF, x;

    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        long long temp = dp0;
        dp0 = std::max(dp1 + 2 * x, dp0);
        dp1 = std::max(temp + x, dp1);
    }

    std::cout << std::max(dp0, dp1) << std::endl;
    return 0;
}