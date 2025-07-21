#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  vector<long long> dp(2);
  dp[0] = 0;
  for (int i = 0; i < N; i++) {
    vector<long long> p(2);
    swap(dp, p);
    for (int j = 0; j < 2; j++) {
      // Option 1: Skip the current enemy
      dp[j] = max(dp[j], p[j]);
      // Option 2: Defeat the current enemy
      if (j == 1) {
        // If the previous enemy was defeated, apply the bonus
        dp[j ^ 1] = max(dp[j ^ 1], p[j] + 2 * A[i]);
      } else {
        // No bonus applied
        dp[j ^ 1] = max(dp[j ^ 1], p[j] + A[i]);
      }
    }
  }
  long long ans = max(dp[0], dp[1]);
  cout << ans << endl;
  return 0;
}