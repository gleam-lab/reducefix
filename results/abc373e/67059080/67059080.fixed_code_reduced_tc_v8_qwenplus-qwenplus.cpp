#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  ll K;
  cin >> N >> M >> K;

  vector<ll> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  // Total remaining votes
  ll total_remaining = K;
  for (ll a : A) {
    total_remaining -= a;
  }

  // Sort the candidates' current votes in descending order
  vector<int> ids(N);
  iota(ids.begin(), ids.end(), 0);
  sort(ids.begin(), ids.end(), [&](int i, int j) { return A[i] > A[j]; });

  vector<ll> ans(N, -1);

  // prefix sum of sorted A
  vector<ll> prefix(N + 1);
  for (int i = 0; i < N; ++i) {
    prefix[i + 1] = prefix[i] + A[ids[i]];
  }

  // For each candidate, binary search on minimum X
  for (int i = 0; i < N; ++i) {
    int idx = ids[i];

    // Binary search on additional votes needed
    ll low = 0, high = total_remaining;
    ll res = -1;

    while (low <= high) {
      ll mid = (low + high) / 2;
      ll current = A[idx] + mid;

      // We need to ensure that at most M-1 candidates have more than current votes
      // So find how many candidates have votes > current
      int left = upper_bound(ids.begin(), ids.end(), -1, [&](int dummy, int x) {
        return current > A[x];
      }) - ids.begin();

      if (left >= M) {
        // Too many candidates ahead, need more votes
        low = mid + 1;
        continue;
      }

      // Try to raise votes of top (M - left - 1) candidates below current
      int can_raise = min(N - left - 1, M - left - 1);
      ll required = 0;
      for (int j = left; j < left + can_raise; ++j) {
        required += max(0LL, current - A[ids[j]] + 1);
      }

      if (required <= total_remaining - mid) {
        res = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    if (res == -1) {
      // Check if already winning
      int cnt = upper_bound(ids.begin(), ids.end(), -1, [&](int dummy, int x) {
        return A[idx] > A[x];
      }) - ids.begin();
      if (cnt < M) {
        ans[idx] = 0;
      }
    } else {
      ans[idx] = res;
    }
  }

  for (ll x : ans) {
    cout << x << " ";
  }
  cout << "\n";

  return 0;
}