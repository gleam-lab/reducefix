#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  vector<long long> dp(2);
  dp[0] = 0;
  dp[1] = A[0]; // Initialize with the first element
  for (int i = 1; i < N; i++) {
    vector<long long> p = dp;
    dp[0] = max(dp[0], p[1]); // Escape the current element
    dp[1] = max(dp[1], p[1] + A[i]); // Reverse the current element
  }
  long long ans = max(dp[0], dp[1]);
  cout << ans << endl;
  return 0;
}