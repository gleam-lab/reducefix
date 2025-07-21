#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  vector<long long> dp(2, LLONG_MIN);
  dp[0] = 0;
  for (int i = 0; i < N; i++) {
    vector<long long> p(2, LLONG_MIN);
    swap(dp, p);
    dp[0] = dp[1] = LLONG_MIN;
    for (int j = 0; j < 2; j++) {
      if (p[j] == LLONG_MIN) continue;
      // Skip current monster
      dp[j] = max(dp[j], p[j]);
      // Defeat current monster normally
      dp[j ^ 1] = max(dp[j ^ 1], p[j] + A[i]);
      // Defeat current monster with double damage (if previous was defeated)
      if (j == 1 && i > 0) {
        dp[j ^ 1] = max(dp[j ^ 1], p[j] + 2 * A[i]);
      }
    }
  }
  long long ans = max(dp[0], dp[1]);
  cout << ans << endl;
  return 0;
}