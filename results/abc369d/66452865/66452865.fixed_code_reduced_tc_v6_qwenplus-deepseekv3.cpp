#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  vector<long long> dp(2);
  dp[0] = 0;
  dp[1] = -1e18; // Initialize to a very small value to represent not possible
  for (int i = 0; i < N; i++) {
    vector<long long> new_dp(2);
    new_dp[0] = max(dp[0], dp[1]); // Not taking current element
    new_dp[1] = dp[0] + A[i]; // Taking current element after not taking previous
    if (i > 0) {
      new_dp[1] = max(new_dp[1], dp[1] + A[i]); // Taking current element after taking previous
    }
    dp = new_dp;
  }
  long long ans = max(dp[0], dp[1]);
  cout << ans << endl;
  return 0;
}