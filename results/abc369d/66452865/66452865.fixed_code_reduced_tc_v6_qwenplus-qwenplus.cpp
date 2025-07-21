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
    vector<long long> p = dp;
    for (int j = 0; j < 2; j++) {
      // Skip monster i
      dp[j] = max(dp[j], p[j]);
      // Defeat monster i
      dp[j ^ 1] = max(dp[j ^ 1], p[j] + A[i]);
      // Defeat monster i with double bonus (if it's not the first monster)
      if (i > 0) {
        dp[j ^ 1] = max(dp[j ^ 1], p[j] + 2 * A[i]);
      }
    }
  }
  
  long long ans = max(dp[0], dp[1]);
  cout << ans << endl;
  
  return 0;
}