#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  
  // dp[0] = last was not killed
  // dp[1] = last was killed
  // dp[2] = last two were killed
  vector<long long> dp(3);
  dp[0] = 0;
  dp[1] = 0;
  dp[2] = 0;
  
  for (int i = 0; i < N; i++) {
    vector<long long> new_dp(3);
    // Option 1: Skip current
    new_dp[0] = max({dp[0], dp[1], dp[2]});
    // Option 2: Kill current (no bonus)
    new_dp[1] = max(dp[0] + A[i], dp[1] + A[i]);
    // Option 3: Kill current with bonus (if previous was killed)
    new_dp[2] = dp[1] + 2 * A[i];
    
    dp = new_dp;
  }
  
  long long ans = max({dp[0], dp[1], dp[2]});
  cout << ans << endl;
  return 0;
}