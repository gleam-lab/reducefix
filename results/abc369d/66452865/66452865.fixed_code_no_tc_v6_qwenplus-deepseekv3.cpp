#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  vector<long long> dp(2);
  dp[0] = 0;
  dp[1] = -1e18;  // Initialize to very small value since we can't select first element with j=1
  for (int i = 0; i < N; i++) {
    vector<long long> new_dp(2, -1e18);
    for (int j = 0; j < 2; j++) {
      // Skip current element
      new_dp[j] = max(new_dp[j], dp[j]);
      // Take current element
      if (j == 0 || i > 0) {  // Can't take first element with j=1
        new_dp[j ^ 1] = max(new_dp[j ^ 1], dp[j] + A[i] * (j == 1 ? 2 : 1));
      }
    }
    dp = new_dp;
  }
  long long ans = max(dp[0], dp[1]);
  cout << ans << endl;
  return 0;
}