#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  
  // dp[j] = max score when considering first i monsters, and ending with j actions used (0 or 1)
  vector<long long> dp(2);
  dp[0] = 0;
  
  for (int i = 0; i < N; i++) {
    vector<long long> new_dp(2, -1e18);  // Initialize with very small values
    
    // Try skipping the current monster
    for (int j = 0; j < 2; j++) {
      new_dp[j] = max(new_dp[j], dp[j]);
      
      // Try using attack
      if (j == 0) {
        new_dp[j + 1] = max(new_dp[j + 1], dp[j] + A[i]);
      } else if (i > 0 && j == 1) {  // Can double only if there's a previous monster
        new_dp[j ^ 1] = max(new_dp[j ^ 1], dp[j] + 2 * A[i]);
      }
    }
    
    dp = new_dp;
  }
  
  long long ans = max(dp[0], dp[1]);
  cout << ans << endl;
  return 0;
}