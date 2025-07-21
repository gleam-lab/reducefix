#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<long long> dp(2);
    dp[0] = 0;  // dp[0] is the score when not flipping
    dp[1] = 0;  // dp[1] is the score when flipping

    for (int i = 0; i < N; i++) {
        vector<long long> new_dp(2, 0);
        // Copy the current states to the new states
        new_dp[0] = dp[0];
        new_dp[1] = dp[1];

        // Escape and keep the current value
        new_dp[0] = max(new_dp[0], dp[1]);  // Escape: Keep the score as is

        // Flip and take the next value
        new_dp[1] = max(new_dp[1], dp[0] + A[i]);  // Flip: Take the score plus the next value
        if (i > 1) {  // Only add 2 times the current value if we have at least 2 elements left
            new_dp[1] = max(new_dp[1], dp[0] + 2 * A[i]);
        }

        // Update the dp array after considering the current operation
        dp = new_dp;
    }

    // The answer is the maximum of the two potential scores
    long long ans = max(dp[0], dp[1]);
    cout << ans << endl;
    return 0;
}