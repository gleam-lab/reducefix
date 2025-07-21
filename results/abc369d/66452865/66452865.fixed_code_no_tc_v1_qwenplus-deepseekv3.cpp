#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  vector<long long> dp(2);
  dp[0] = 0;
  dp[1] = -1e18; // Initialize to negative infinity to represent invalid state
  for (int i = 0; i < N; i++) {
    vector<long long> new_dp(2);
    // Option 1: Skip current monster
    new_dp[0] = max(dp[0], dp[1]);
    // Option 2: Attack current monster (normal attack)
    new_dp[1] = dp[0] + A[i];
    // Option 3: If previous was attack, do bonus attack
    if (i > 0 && dp[1] != -1e18) {
      new_dp[1] = max(new_dp[1], dp[1] + 2 * A[i]);
    }
    dp = new_dp;
  }
  long long ans = max(dp[0], dp[1]);
  cout << ans << endl;
  return 0;
}