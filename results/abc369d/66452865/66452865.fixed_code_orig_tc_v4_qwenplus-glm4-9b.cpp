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
  dp[1] = 0; // Initialize both states to 0
  
  for (int i = 0; i < N; i++) {
    vector<long long> p(2);
    p[0] = dp[1]; // Carry forward the last value of dp[1] to p[0]
    p[1] = dp[0]; // Carry forward the last value of dp[0] to p[1]
    
    // Update p[0] and p[1] based on current logic
    p[0] = max(p[0], p[1]);
    p[1] = max(p[1], p[0] + A[i]);
    
    if (i > 1) { // Only add twice the current A[i] if i > 1
      p[1] = max(p[1], p[0] + 2 * A[i]);
    }
    
    // Move the new values to dp
    dp[0] = p[0];
    dp[1] = p[1];
  }
  
  long long ans = max(dp[0], dp[1]);
  cout << ans << endl;
  return 0;
}