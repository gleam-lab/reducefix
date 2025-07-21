#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<long long> dp(2);
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        std::vector<long long> p(2);
        std::swap(dp, p);
        for (int j = 0; j < 2; j++) {
            dp[j] = std::max(dp[j], p[j]);
            if (j == 0 || i > 0) {
                dp[j ^ 1] = std::max(dp[j ^ 1], p[j] + A[i]);
            }
        }
    }

    long long result = std::max(dp[0], dp[1]);
    std::cout << result << std::endl;

    return 0;
}