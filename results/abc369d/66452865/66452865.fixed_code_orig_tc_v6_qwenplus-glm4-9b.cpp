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
    // Copy dp to p
    p[0] = dp[0];
    p[1] = dp[1];
    
    // Calculate the maximum scores for taking and not taking the current item
    for (int j = 0; j < 2; j++) {
      long long current = p[j]; // Copy current value for modification
      // Escape case
      dp[j] = max(dp[j], current);
      // Take case
      dp[j ^ 1] = max(dp[j ^ 1], current + (j == 1 ? A[i] : 0));
    }
  }
  long long ans = max(dp[0], dp[1]);
  cout << ans << endl;
  return 0;
}