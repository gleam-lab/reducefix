#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  vector<long long> dp(2);
  dp[0] = 0;
  dp[1] = -1e18; // Initialize to negative infinity to handle first step properly
  for (int i = 0; i < N; i++) {
    vector<long long> new_dp(2, -1e18);
    // Option 1: Skip the current monster
    new_dp[0] = max(dp[0], dp[1]);
    // Option 2: Kill the current monster
    new_dp[1] = dp[0] + A[i];
    if (i >= 1 && dp[1] != -1e18) {
      new_dp[1] = max(new_dp[1], dp[1] + A[i] * 2);
    }
    dp = new_dp;
  }
  long long ans = max(dp[0], dp[1]);
  cout << ans << endl;
  return 0;
}