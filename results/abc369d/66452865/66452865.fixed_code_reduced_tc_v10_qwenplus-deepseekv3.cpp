#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  vector<long long> dp(2);
  dp[0] = 0;
  dp[1] = -1e18; // Initialize to a very small number to handle the first element correctly
  for (int i = 0; i < N; i++) {
    vector<long long> p = dp;
    // Skip the current element
    dp[0] = max(p[0], p[1]);
    // Take the current element
    dp[1] = p[0] + A[i];
    if (i > 0) {
      dp[1] = max(dp[1], p[1] + A[i]);
    }
  }
  long long ans = max(dp[0], dp[1]);
  cout << ans << endl;
  return 0;
}