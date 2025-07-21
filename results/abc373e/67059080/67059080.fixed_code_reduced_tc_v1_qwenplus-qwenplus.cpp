#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  ll K;
  cin >> N >> M >> K;

  vector<pair<ll, int>> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i].first;
    A[i].second = i;
  }

  vector<ll> ans(N, -1);

  // Sort candidates by current votes
  sort(A.begin(), A.end());

  // Prefix sum array to help with range sum queries
  vector<ll> prefix(N + 1);
  for (int i = 0; i < N; ++i)
    prefix[i + 1] = prefix[i] + A[i].first;

  // Total used votes so far
  ll total_used = prefix[N];
  ll remaining_votes = K - total_used;

  // For each candidate, find minimum additional votes needed
  for (int i = 0; i < N; ++i) {
    ll current = A[i].first;
    int left = 0, right = remaining_votes;
    ll res = -1;

    while (left <= right) {
      ll mid = (left + right) / 2;
      ll my_total = current + mid;
      ll need = 0;

      // Binary search to find how many candidates are strictly stronger than me
      int l = 0, r = N;
      while (l < r) {
        int m = (l + r) / 2;
        if (A[m].first > my_total)
          r = m;
        else
          l = m + 1;
      }
      int stronger = l;

      // If I'm among the M strongest, I win
      if (N - stronger < M) {
        res = mid;
        right = mid - 1;
        continue;
      }

      // Otherwise, try to beat some of the stronger ones
      int required_to_beat = (N - stronger) - (M - 1);
      if (required_to_beat <= 0) {
        res = mid;
        right = mid - 1;
        continue;
      }

      // Compute how many votes we need to surpass required_to_beat candidates
      int from = stronger;
      int to = stronger + required_to_beat;

      ll total_needed = 0;
      if (to <= N) {
        total_needed = (my_total + 1) * required_to_beat - (prefix[to] - prefix[from]);
      }

      if (total_needed <= remaining_votes - mid) {
        res = mid;
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    if (res != -1) {
      ans[A[i].second] = res;
    } else {
      ans[A[i].second] = -1;
    }
  }

  // Print results in original order
  for (int i = 0; i < N; ++i)
    cout << (ans[i] == -1 ? -1 : max(0LL, ans[i])) << " ";
  cout << endl;

  return 0;
}