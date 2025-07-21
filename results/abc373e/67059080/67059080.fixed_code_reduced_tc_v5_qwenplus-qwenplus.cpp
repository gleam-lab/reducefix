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

  // Sort the candidates by current votes
  sort(A.begin(), A.end());

  // Prefix sum array to help with efficient range sum queries
  vector<ll> prefix(N + 1);
  for (int i = 0; i < N; ++i)
    prefix[i + 1] = prefix[i] + A[i].first;

  ll total_remaining = K - (prefix[N] - prefix[0]);

  for (int i = 0; i < N; ++i) {
    int idx = i;
    ll current_votes = A[i].first;

    // Binary search on minimum additional votes needed
    ll low = 0, high = total_remaining;
    while (low <= high) {
      ll mid = (low + high) / 2;
      ll extended_votes = current_votes + mid;

      // Find how many candidates have votes > extended_votes
      int left = i + 1, right = N;
      while (left < right) {
        int m = (left + right) / 2;
        if (A[m].first > extended_votes)
          left = m + 1;
        else
          right = m;
      }
      int start_idx = left;

      // We need to ensure at most M-1 candidates have strictly more votes
      int needed_less_or_equal = M - 1;

      // How many candidates are already above us?
      int already_above = N - start_idx + 1;

      if (already_above >= M) {
        // Too many candidates already have more votes
        low = mid + 1;
        continue;
      }

      needed_less_or_equal -= already_above;

      if (needed_less_or_equal < 0) {
        // Already enough candidates below us
        ans[A[i].second] = mid;
        high = mid - 1;
        continue;
      }

      // Try to cap the top (needed_less_or_equal) candidates to <= extended_votes
      int available_to_cap = start_idx - 1 - i;

      // Use binary search to find how many we can cap
      int l = 0, r = min(available_to_cap, needed_less_or_equal);
      int ok = 0;
      while (l <= r) {
        int m = (l + r) / 2;
        // First m candidates from this segment
        ll required = extended_votes * m - (prefix[start_idx] - prefix[start_idx - m]);
        if (required <= total_remaining - mid) {
          ok = m;
          l = m + 1;
        } else {
          r = m - 1;
        }
      }

      if (ok >= needed_less_or_equal) {
        ans[A[i].second] = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    if (ans[A[i].second] == -1 && low > total_remaining) {
      // Check if already elected
      int cnt = 0;
      for (int j = 0; j < N; ++j) {
        if (j != i && A[j].first > current_votes)
          cnt++;
      }
      if (cnt < M)
        ans[A[i].second] = 0;
    }
  }

  for (ll x : ans)
    cout << x << " ";
  cout << "\n";

  return 0;
}