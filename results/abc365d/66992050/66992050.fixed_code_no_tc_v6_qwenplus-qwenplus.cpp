#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  string S;
  cin >> N >> S;

  // Mapping of moves to indices: R=0, P=1, S=2
  vector<vector<int>> transitions = {
      {0, 1, -1}, // R beats S (-1 means lose), R loses to P (1 means win)
      {-1, 0, 1}, // P beats R (-1 means win), P loses to S (1 means lose)
      {1, -1, 0}  // S beats P (1 means lose), S loses to R (-1 means win)
  };

  // DP[i][j]: minimum number of changes to make first i+1 characters end with move j
  // where j = 0 (R), 1 (P), 2 (S)
  vector<vector<int>> dp(N, vector<int>(3, INT_MAX));

  // Initialize for first character
  for (int j = 0; j < 3; ++j) {
    char moves[] = {'R', 'P', 'S'};
    dp[0][j] = (S[0] != moves[j]) ? 1 : 0;
  }

  for (int i = 1; i < N; ++i) {
    for (int curr = 0; curr < 3; ++curr) {
      for (int prev = 0; prev < 3; ++prev) {
        if (transitions[prev][curr] <= 0) { // curr must not beat prev
          dp[i][curr] = min(dp[i][curr], dp[i-1][prev] + ((S[i] != ('R'+curr)) ? 1 : 0));
        }
      }
    }
  }

  cout << *min_element(dp[N-1].begin(), dp[N-1].end());
  return 0;
}