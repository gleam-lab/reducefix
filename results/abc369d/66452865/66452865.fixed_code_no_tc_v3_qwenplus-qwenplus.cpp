#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  // dp[j] = max score when considering up to current monster, ending with state j
  // j = 0: even number of monsters defeated (not using double damage)
  // j = 1: odd number of monsters defeated (not using double damage)
  vector<long long> dp(2);
  dp[0] = 0;

  for (int i = 0; i < N; i++) {
    vector<long long> new_dp = dp;  // start with not taking A[i]

    for (int j = 0; j < 2; j++) {
      // Take A[i] without double damage
      new_dp[j ^ 1] = max(new_dp[j ^ 1], dp[j] + A[i]);

      // Take A[i] with double damage (only possible if at least one previous monster was skipped)
      if (i > 0) {
        new_dp[j ^ 1] = max(new_dp[j ^ 1], dp[j] + 2 * A[i]);
      }
    }

    dp = new_dp;
  }

  cout << max(dp[0], dp[1]) << endl;
  return 0;
}