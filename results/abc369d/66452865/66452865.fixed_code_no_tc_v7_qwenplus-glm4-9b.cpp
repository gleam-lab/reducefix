#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  
  // dp[0] represents the maximum sum achievable without flipping at the current step
  // dp[1] represents the maximum sum achievable after flipping at the current step
  vector<long long> dp(2, 0);
  
  for (int i = 0; i < N; i++) {
    vector<long long> p(2);
    swap(dp, p);
    
    // Calculate new states based on current dp values and A[i]
    p[0] = max(p[0], p[1] + A[i]);   // Take the current value and continue
    p[1] = max(p[1], p[0] + A[i]);   // Flip the current value and continue
    
    if (i > 0) {  // Check if we have more than one element already processed
      p[0] = max(p[0], p[1] + 2 * A[i]);  // Consider taking two consecutive elements
      p[1] = max(p[1], p[0]);           // Consider flipping and taking the previous state
    }
    
    // Update dp to the new calculated values
    dp = p;
  }
  
  // The answer is the maximum value between the two possible end states
  long long ans = max(dp[0], dp[1]);
  cout << ans << endl;
  return 0;
}