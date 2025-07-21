#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M, K;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  cin >> N >> M >> K;

  vector<ll> A(N);
  for (ll &a : A) cin >> a;

  // Sort candidates by their current votes in descending order
  sort(A.rbegin(), A.rend());

  vector<ll> remaining_votes(K - accumulate(A.begin(), A.end(), 0LL));
  sort(remaining_votes.begin(), remaining_votes.end());

  vector<ll> results(N, -1);
  for (int i = 0; i < N; ++i) {
    if (i + 1 < M) {
      // If there are less than M candidates ahead, they will not be elected
      results[i] = -1;
    } else {
      // Find the minimum additional votes needed to ensure victory
      ll votes_needed = M - (i + 1);
      results[i] = votes_needed;

      // Find the smallest number of remaining votes that is greater than votes_needed
      auto it = upper_bound(remaining_votes.begin(), remaining_votes.end(), votes_needed);
      if (it != remaining_votes.begin()) {
        results[i] = *--it; // This is the minimum additional votes needed
      } else {
        // If no such votes are available, the candidate cannot be elected
        results[i] = -1;
      }
    }
  }

  // Output the results
  for (ll res : results) {
    cout << res << ' ';
  }
  cout << '\n';

  return 0;
}