#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  
  // dp[j] = max score when considering up to current monster, and ending with parity j
  // parity: 0 = even number of monsters defeated, 1 = odd number of monsters defeated
  vector<long long> dp(2);
  dp[0] = 0;  // Initially, we can consider we've defeated 0 monsters (even)

  for (int i = 0; i < N; i++) {
    vector<long long> next_dp = dp;  // Start by not defeating the current monster

    // Try defeating the current monster
    next_dp[i % 2 ^ 1] = max(next_dp[i % 2 ^ 1], dp[i % 2] + A[i]);

    // If this is at least the third monster, try defeating two in a row with double reward for second
    if (i >= 1) {
      next_dp[(i - 1) % 2] = max(next_dp[(i - 1) % 2], dp[(i - 1) % 2] + 2 * A[i]);
    }

    dp = next_dp;
  }

  long long ans = max(dp[0], dp[1]);
  cout << ans << endl;
  return 0;
}