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
      // Skip monster
      dp[j] = max(dp[j], p[j]);
      // Defeat monster
      dp[j ^ 1] = max(dp[j ^ 1], p[j] + A[i]);
      // If previous was defeated and we can use special move on this one
      if (j == 1 && i > 0) {
        dp[j ^ 1] = max(dp[j ^ 1], p[j] + A[i] * 2);
      }
    }
  }
  long long ans = max(dp[0], dp[1]);
  cout << ans << endl;
  return 0;
}