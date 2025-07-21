#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  // dp[j] = 最大価値、j=0:直前を使用していない, j=1:直前を使用している
  vector<long long> dp(2);
  dp[0] = 0;
  dp[1] = A[0]; // 初期状態の設定

  for (int i = 1; i < N; i++) {
    vector<long long> new_dp(2);
    // 直前の敵を倒していない場合
    new_dp[0] = max(dp[0], dp[1]); // A[i]を使用しない
    // 直前の敵を倒している場合
    new_dp[1] = dp[0] + A[i]; // A[i]を使用する
    if (i > 1) {
      // 連続で使用しない -> 前々回に使用して、前回使わずに今回使用
      new_dp[1] = max(new_dp[1], dp[1] + 2 * A[i]);
    }
    dp = new_dp;
  }

  long long ans = max(dp[0], dp[1]);
  cout << ans << endl;
  return 0;
}