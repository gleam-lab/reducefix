#include <iostream>
#include <vector>
#include <algorithm>
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
    swap(dp[1], p[0]);  // Corrected: Swap dp[1] with p[0] directly instead of swapping the entire dp array
    p[1] = max(p[0], p[1]);
    p[1] = max(p[1], p[0] + A[i]);
    if (i > 0) p[1] = max(p[1], p[0] + 2 * A[i]);  // Ensured that i > 0 before doubling A[i]
    swap(dp[1], p[1]);  // Corrected: Swap dp[1] with p[1] directly instead of swapping the entire dp array
    swap(dp[0], p[0]);  // Corrected: Swap dp[0] with p[0] directly instead of swapping the entire dp array
    dp[0] = max(dp[0], p[0]);
  }
  long long ans = max(dp[0], dp[1]);
  cout << ans << endl;
  return 0;
}