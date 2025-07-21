#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  // dp[j] = 最大利益、jは前回の行動に関する状態 (0:休んだ, 1:戦った)
  vector<long long> dp(2);
  dp[0] = 0;  // 初期状態: 初日より前に休んでいる

  for (int i = 0; i < N; i++) {
    vector<long long> new_dp(2, -1e18);  // 新しい状態

    // 現在の日iで行動を選択
    // 前日の状態から遷移する

    // 現在休む -> 前日はどちらでもよい
    new_dp[0] = max(dp[0], dp[1]);

    // 現在戦う -> 前日に休んでいなければ倒せない
    if (i == 0) {
      // 初日は特別扱い（前日前々日がない）
      new_dp[1] = A[i];
    } else {
      // 前日に休んでいれば、その状態から戦える
      new_dp[1] = dp[0] + A[i];

      // 前々日に休んでいて、前日に戦っていれば、連続攻撃ボーナス
      if (i >= 1 && i % 2 == 0) {  // 問題文の条件に応じて調整（例：偶数日目など）
        new_dp[1] = max(new_dp[1], dp[0] + 2 * A[i]);
      }
    }

    dp = new_dp;
  }

  long long ans = max(dp[0], dp[1]);
  cout << ans << endl;
  return 0;
}