#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
ll K;

struct Node {
  ll val;
  int idx;
};

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  cin >> N >> M >> K;

  vector<Node> a(N + 5);
  vector<ll> votes(N + 5); // To store votes from input
  vector<ll> dp(N + 5, 0); // DP array for storing additional votes needed

  for (int i = 1; i <= N; ++i) {
    cin >> a[i].val;
    a[i].idx = i;
    votes[i] = a[i].val;
  }

  // Sort based on votes received
  sort(a.begin() + 1, a.begin() + N + 1, [](const Node &A, const Node &B) {
    return A.val < B.val;
  });

  // Calculate the total votes received so far
  ll total_votes = 0;
  for (int i = 1; i <= N; ++i) {
    total_votes += a[i].val;
  }

  K -= total_votes; // Remaining votes

  // Binary search to find the minimum additional votes needed
  for (int i = 1; i <= N; ++i) {
    if (N - i < M) {
      cout << -1 << " ";
      continue;
    }

    ll low = 0, high = K + 1;
    while (low < high - 1) {
      ll mid = (low + high) / 2;
      ll required_votes = 0;

      // Calculate the number of candidates that would have more votes than the current candidate
      int candidates_with_more_votes = 0;
      for (int j = 1; j <= N; ++j) {
        required_votes += (a[j].val + mid - 1) / mid; // ceil function
        if (j != i && required_votes >= M) break;
      }

      if (required_votes < M) {
        high = mid;
      } else {
        low = mid;
      }
    }

    dp[i] = low;
  }

  // Output the result
  for (ll vote : dp) {
    cout << vote << " ";
  }

  return 0;
}