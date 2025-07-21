#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    
    long long dp[2] = {0, 0};  // Use long long to prevent overflow
    
    for (int i = 0; i < N; i++) {
        long long next_dp[2] = {0, 0};
        
        // Skip the current element
        next_dp[0] = max(next_dp[0], dp[0]);
        next_dp[1] = max(next_dp[1], dp[1]);
        
        // Take the current element
        next_dp[1] = max(next_dp[1], dp[0] + A[i]);
        
        if (i > 0) {
            next_dp[1] = max(next_dp[1], dp[1] + 2 * A[i]);  // Allow taking the second element in a row
        }
        
        dp[0] = next_dp[0];
        dp[1] = next_dp[1];
    }
    
    cout << max(dp[0], dp[1]) << endl;
    return 0;
}