#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  vector<long long> dp(2); // dp[0] is the max value with the last operation being escape, and dp[1] is the same with the last operation being reverse
  dp[0] = 0; // We start with the "escape" operation having 0 value
  dp[1] = 0; // We start with the "reverse" operation having 0 value

  for (int i = 0; i < N; i++) {
    vector<long long> next_dp(2);
    for (int j = 0; j < 2; j++) {
      // Escape the current number without any operation
      next_dp[j] = max(next_dp[j], dp[j]);
      
      // Reverse the current number, this adds A[i] to the "reverse" state
      next_dp[1 ^ j] = max(next_dp[1 ^ j], dp[j] + A[i]);
    }
    dp = next_dp; // Update dp to the next state after processing the current number
  }

  // The answer is the maximum value between the two states
  long long ans = max(dp[0], dp[1]);
  cout << ans << endl;
  return 0;
}