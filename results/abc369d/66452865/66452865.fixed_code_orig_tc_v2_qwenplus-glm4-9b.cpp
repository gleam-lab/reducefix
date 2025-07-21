#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    // Initialize dp array with the base case
    long long dp[2] = {0, 0};

    for (int i = 0; i < N; ++i) {
        long long current_dp[2] = {0, 0};
        // Escape strategy
        current_dp[0] = max(dp[0], dp[1]);

        // Flip strategy
        current_dp[1] = max(dp[1], dp[0] + A[i]);
        if (i > 0) {
            current_dp[1] = max(current_dp[1], dp[0] + 2 * A[i]);
        }

        // Update dp for the next iteration
        dp[0] = current_dp[0];
        dp[1] = current_dp[1];
    }

    cout << max(dp[0], dp[1]) << endl;

    return 0;
}