#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    if (n == 1) {
        std::cout << a[0] << std::endl;
        return 0;
    }

    std::vector<long long> dp(n, 0);
    dp[0] = a[0];
    dp[1] = std::max(a[0] + 2LL * a[1], a[1]);

    for (int i = 2; i < n; ++i) {
        dp[i] = std::max(dp[i-2] + 2LL * a[i], dp[i-1] + a[i]);
    }

    std::cout << dp[n-1] << std::endl;
    return 0;
}