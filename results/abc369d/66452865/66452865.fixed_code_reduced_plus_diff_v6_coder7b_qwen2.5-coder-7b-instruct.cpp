#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    // Initialize DP array
    vector<long long> dp(2);
    dp[0] = 0;
    dp[1] = 0;

    for (int i = 0; i < N; i++) {
        vector<long long> next_dp(2);
        for (int j = 0; j < 2; j++) {
            // Stay at the same position
            next_dp[j] = max(next_dp[j], dp[j]);
            // Move to the next position
            next_dp[j ^ 1] = max(next_dp[j ^ 1], dp[j] + A[i]);
            if (i > 0 && j == 1) next_dp[j ^ 1] = max(next_dp[j ^ 1], dp[j] + 2 * A[i]);
        }
        dp = next_dp;
    }

    long long ans = max(dp[0], dp[1]);
    cout << ans << endl;

    return 0;
}