#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
ll K;
ll votes_so_far;

struct Node {
  ll val;
  int idx;
};

int main() {
  cin >> N >> M >> K;
  votes_so_far = 0;
  cin >> votes_so_far;

  vector<Node> a(N + 5), sorted_a(N + 5);
  for (int i = 0; i < N; i++) {
    cin >> a[i].val;
    a[i].idx = i;
  }

  // Sort candidates based on their current votes
  sort(a.begin(), a.begin() + N, [](const Node& x, const Node& y) {
    return x.val > y.val;
  });

  // Sort to get the index in sorted order
  for (int i = 0; i < N; i++) sorted_a[i] = a[i];

  // Precompute prefix sums
  vector<ll> prefix(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    prefix[i] = prefix[i - 1] + a[i - 1].val;
  }

  vector<ll> required_votes(N, -1);

  // Check if any candidate is already guaranteed to win
  for (int i = 0; i < N; i++) {
    ll required = prefix[N] - prefix[i] + (M - 1) - (prefix[N] - prefix[N - M]);
    if (a[i].val + votes_so_far >= required) {
      required_votes[i] = 0;
    }
  }

  // Binary search for the minimum votes required
  for (int i = 0; i < N; i++) {
    if (required_votes[i] >= 0) continue;
    ll low = 0, high = K - votes_so_far;
    while (low < high) {
      ll mid = (low + high + 1) / 2;
      ll votes_needed = prefix[N] - prefix[i] + M - 1 - (prefix[N] - prefix[N - M]);
      if (a[i].val + votes_needed + mid >= votes_needed) {
        high = mid - 1;
      } else {
        low = mid;
      }
    }
    required_votes[i] = low;
  }

  // Output the result for each candidate
  for (int i = 0; i < N; i++) {
    cout << required_votes[i] << ' ';
  }
  cout << '\n';

  return 0;
}