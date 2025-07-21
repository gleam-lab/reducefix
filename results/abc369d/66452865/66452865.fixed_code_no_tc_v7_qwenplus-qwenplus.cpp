#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  // dp[j] = maximum score when considering up to current monster, with j indicating:
  // j = 0: even number of monsters defeated (or none)
  // j = 1: odd number of monsters defeated
  vector<long long> dp(2);
  dp[0] = 0;

  for (int i = 0; i < N; i++) {
    vector<long long> prev = dp;  // copy previous state
    for (int j = 0; j < 2; j++) {
      // Option 1: skip the current monster
      dp[j] = max(dp[j], prev[j]);

      // Option 2: defeat the current monster
      int new_j = j ^ 1;
      long long gain = A[i];
      if (j == 1) gain *= 2;  // double reward if previously odd number of monsters defeated

      dp[new_j] = max(dp[new_j], prev[j] + gain);
    }
  }

  long long ans = max(dp[0], dp[1]);
  cout << ans << endl;
  return 0;
}