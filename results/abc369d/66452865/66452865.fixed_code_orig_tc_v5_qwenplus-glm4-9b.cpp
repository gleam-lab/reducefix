#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  vector<long long> dp(2);
  dp[0] = 0;
  
  // For i > 1, we can consider the doubling condition.
  for (int i = 0; i < N; i++) {
    vector<long long> p = dp;  // Copy current dp to p
    dp[0] = max(dp[0], p[0]);   // Skip current element
    dp[1] = max(dp[1], p[1] + A[i]);  // Take current element once
    if (i > 1 && A[i] == A[i - 1]) {
      dp[1] = max(dp[1], p[0] + A[i] + A[i - 1]);  // Take current element twice
    }
    if (i > 0) {
      dp[1] = max(dp[1], p[1] + 2 * A[i]);  // Take current element twice, considering previous element
    }
  }
  long long ans = max(dp[0], dp[1]);
  cout << ans << endl;
  return 0;
}