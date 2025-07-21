#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  
  // dp[0] = maximum value without taking previous element
  // dp[1] = maximum value with taking previous element
  vector<long long> dp(2, 0);
  
  for (int i = 0; i < N; i++) {
    vector<long long> new_dp(2);
    // Option 1: Skip current element
    new_dp[0] = max(dp[0], dp[1]);
    // Option 2: Take current element
    // Can either come from previous skip or take
    new_dp[1] = dp[0] + A[i];
    // Additional bonus if previous was taken
    if (i > 0) new_dp[1] = max(new_dp[1], dp[1] + 2 * A[i]);
    
    dp = new_dp;
  }
  
  cout << max(dp[0], dp[1]) << endl;
  return 0;
}