#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  vector<long long> dp(2);
  dp[0] = 0;
  dp[1] = 0;
  for (int i = 0; i < N; i++) {
    vector<long long> p(2);
    swap(dp, p);
    for (int j = 0; j < 2; j++) {
      // éãã¨ã
      p[j] = max(p[j], dp[j]);
      // åãã¨ã
      p[j ^ 1] = max(p[j ^ 1], dp[j] + A[i]);
      if (i > 1) p[j ^ 1] = max(p[j ^ 1], dp[j] + 2 * A[i]);  // ä¿®æ­£: i>1
    }
    dp = p;
  }
  cout << max(dp[0], dp[1]) << endl;
  return 0;
}