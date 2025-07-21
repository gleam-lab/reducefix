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
    dp[0] = 0;
    dp[1] = 2 * A[0];  // Initialize dp[1] with twice the first element since we can take two by taking the first element twice
    for (int i = 1; i < N; i++) {
        vector<long long> next_dp(2);
        next_dp[0] = max(dp[0], dp[1]);
        next_dp[1] = max(dp[1], dp[1] + A[i]);  // Continue with current strategy
        next_dp[1] = max(next_dp[1], dp[0] + 2 * A[i]);  // Take two by taking the current element twice
        dp = next_dp;
    }
    cout << max(dp[0], dp[1]) << endl;
    return 0;
}