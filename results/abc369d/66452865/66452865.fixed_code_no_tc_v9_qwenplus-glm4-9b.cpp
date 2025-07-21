#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    
    vector<long long> dp(2);
    dp[0] = 0;
    dp[1] = 0;  // Initialize dp[1] to 0 instead of using the swap trick
    
    for (int i = 0; i < N; i++) {
        vector<long long> next_dp(2);
        for (int j = 0; j < 2; j++) {
            // éãã¨ã
            next_dp[j] = max(next_dp[j], dp[j]);
            // åãã¨ã
            next_dp[j ^ 1] = max(next_dp[j ^ 1], dp[j] + A[i]);
            if (j == 1 && i > 0) next_dp[j ^ 1] = max(next_dp[j ^ 1], dp[j] + 2 * A[i]);  // Remove the incorrect i > 1
        }
        dp = next_dp;  // Update dp to the next state
    }
    
    long long ans = max(dp[0], dp[1]);
    cout << ans << endl;
    
    return 0;
}