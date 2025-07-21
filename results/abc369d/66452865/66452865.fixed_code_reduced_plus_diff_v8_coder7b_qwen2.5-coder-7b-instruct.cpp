#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::vector<long long> A(N);
    for (int i = 0; i < N; ++i) std::cin >> A[i];

    std::vector<long long> dp(2);
    dp[0] = 0;
    for (const auto& a : A) {
        std::vector<long long> next_dp(2);
        for (int j = 0; j < 2; ++j) {
            // Skip current element
            next_dp[j] = std::max(next_dp[j], dp[j]);
            // Take current element
            next_dp[j ^ 1] = std::max(next_dp[j ^ 1], dp[j] + a);
            if (j == 1) next_dp[j ^ 1] = std::max(next_dp[j ^ 1], dp[j] + 2 * a); // Only double the value when taking the second element
        }
        dp = next_dp;
    }

    std::cout << std::max(dp[0], dp[1]) << std::endl;
    return 0;
}