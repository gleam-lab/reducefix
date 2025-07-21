#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    
    // Use a larger size for dp to handle large inputs
    vector<long long> dp(2, 0);
    
    for (int i = 0; i < N; i++) {
        vector<long long> next_dp(2, 0);
        next_dp[0] = max(dp[0], dp[1]);
        next_dp[1] = max(dp[1], dp[1] + A[i]);
        
        if (i > 0) {
            next_dp[0] = max(next_dp[0], dp[0] + A[i]);
            next_dp[1] = max(next_dp[1], dp[0] + 2 * A[i]);
        }
        
        dp = next_dp;
    }
    
    long long ans = max(dp[0], dp[1]);
    cout << ans << endl;
    
    return 0;
}