#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  
  if (N == 1) {
    cout << A[0] << endl;
    return 0;
  }
  
  vector<vector<long long>> dp(N, vector<long long>(2, 0));
  dp[0][0] = 0;
  dp[0][1] = A[0];
  
  for (int i = 1; i < N; i++) {
    // Current element not taken
    dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
    
    // Current element taken normally
    dp[i][1] = dp[i-1][0] + A[i];
    
    // Current element taken with double multiplier if previous was taken
    if (i >= 1) {
      dp[i][1] = max(dp[i][1], dp[i-1][1] + 2 * A[i]);
    }
  }
  
  long long ans = max(dp[N-1][0], dp[N-1][1]);
  cout << ans << endl;
  return 0;
}