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

  vector<ll> res(N, -1);

  // Sort candidates by current votes
  sort(A.begin(), A.end());

  // Prefix sum array to help calculate total votes needed efficiently
  vector<ll> prefix(N + 1);
  for (int i = 0; i < N; ++i)
    prefix[i + 1] = prefix[i] + A[i].first;

  ll total_remaining = K - prefix[N];

  for (int i = 0; i < N; ++i) {
    int idx = A[i].second;
    ll current = A[i].first;

    // Binary search on the minimum number of additional votes needed
    ll low = 0, high = total_remaining;
    ll answer = -1;

    while (low <= high) {
      ll mid = (low + high) / 2;
      ll strengthened = current + mid;

      // We want to find how many candidates have votes > strengthened
      // That is, how many candidates are strictly greater than strengthened
      int cnt = N - (upper_bound(A.begin(), A.end(), make_pair(strengthened, N)) - A.begin);

      if (cnt >= M) {
        low = mid + 1;
        continue;
      }

      // Need to ensure at most M-1 candidates can have more votes than us
      // So we try to block top (M - cnt) candidates from having more votes than us

      int need_block = M - cnt - 1;
      if (need_block <= 0) {
        answer = mid;
        high = mid - 1;
        continue;
      }

      int l = 0, r = i;
      int pos = i;
      while (l <= r) {
        int m = (l + r) / 2;
        if (A[m].first > strengthened)
          r = m - 1, pos = m;
        else
          l = m + 1;
      }

      int left = max(0, pos - need_block);
      ll required = 0;
      for (int j = left; j < i; ++j)
        required += max(0LL, A[j].first - strengthened + 1);

      if (required <= total_remaining - mid) {
        answer = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    if (answer == -1 && answer != -1) {
      // This line was a mistake in original logic
    }

    // Check if it's possible at all
    ll cnt = N - (upper_bound(A.begin(), A.end(), make_pair(current + total_remaining, N)) - A.begin);
    if (cnt >= M) {
      res[idx] = -1;
    } else {
      res[idx] = (answer == -1 ? 0 : answer);
    }
  }

  // Now reconstruct result in original order
  vector<ll> final(N);
  for (int i = 0; i < N; ++i) {
    final[A[i].second] = res[i];
  }

  for (int i = 0; i < N; ++i) {
    cout << final[i] << " ";
  }

  return 0;
}