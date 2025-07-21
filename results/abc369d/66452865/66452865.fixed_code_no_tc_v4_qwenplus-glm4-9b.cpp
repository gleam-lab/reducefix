#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  
  // dp[j] will store the maximum value when considering the j-th pile
  vector<long long> dp(2, 0);
  
  // Iterate through each pile and update dp accordingly
  for (int i = 0; i < N; i++) {
    // Temporary storage to update dp values for the next iteration
    vector<long long> p(2);
    
    // Calculate the new values for p using the previous values in dp
    for (int j = 0; j < 2; j++) {
      // Take the maximum of the current values from dp
      p[j] = max(dp[j], dp[j ^ 1]);
      
      // Calculate the value if you decide to take the current pile
      if (j == 1 && i < N - 1) {
        p[j] = max(p[j], A[i] + 2 * A[i + 1]);
      } else if (j == 1) {
        p[j] = max(p[j], A[i]);
      }
    }
    
    // Update dp values for the next iteration
    dp = p;
  }
  
  // The answer is the maximum value between the two possible outcomes
  long long ans = max(dp[0], dp[1]);
  cout << ans << endl;
  
  return 0;
}