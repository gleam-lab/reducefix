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

  // Remaining votes to be distributed
  ll remaining = K;
  for (ll a : A) {
    remaining -= a;
  }

  vector<ll> res(N, -1);

  // We will sort the candidates by current votes
  vector<int> ids(N);
  for (int i = 0; i < N; ++i) ids[i] = i;
  sort(ids.begin(), ids.end(), [&](int i, int j) { return A[i] < A[j]; });

  // Prefix sums of sorted votes
  vector<ll> prefix(N + 1);
  for (int i = 0; i < N; ++i) {
    prefix[i + 1] = prefix[i] + A[ids[i]];
  }

  for (int idx = 0; idx < N; ++idx) {
    int i = ids[idx]; // Current candidate index in original array
    ll base = A[i];

    // Binary search on needed extra votes
    ll low = 0, high = remaining;
    ll answer = -1;

    while (low <= high) {
      ll mid = (low + high) / 2;
      ll total = base + mid;

      // We need to ensure that at most M-1 candidates have strictly more than total
      // So find how many candidates are *strictly greater* than total

      // Use binary search on the sorted list
      int l = 0, r = N;
      while (l < r) {
        int m = (l + r) / 2;
        if (A[ids[m]] > total)
          r = m;
        else
          l = m + 1;
      }
      int cnt_strict_greater = l;

      // From those who are <= total, we can increase up to total
      // To block them from being > total, we can raise them to at most `total`
      ll needed = 0;
      ll count = idx;
      ll sum = prefix[idx]; // sum of all A[j] where A[j] < A[i]

      // Calculate how much we need to boost top `x` candidates to `total`
      // x is number of candidates we must block to ensure less than M have > total
      int required_block = M - cnt_strict_greater;
      if (required_block <= 0) {
        res[i] = max(0LL, mid);
        break;
      }

      // We need to raise the smallest `required_block` candidates among ids[0..idx-1] to total
      if (required_block > idx) {
        // Not enough candidates below i to block
        high = mid - 1;
        continue;
      }

      ll sum_needed = required_block * total;
      ll sum_available = prefix[idx] - prefix[idx - required_block];
      needed = sum_needed - sum_available;

      if (needed <= remaining - mid) {
        // Can afford this configuration => candidate i is safe with mid extra votes
        answer = mid;
        high = mid - 1;
      } else {
        // Cannot afford => try higher X
        low = mid + 1;
      }
    }

    if (answer == -1) {
      // Try one last time with full remaining
      ll total = base + remaining;
      int l = 0, r = N;
      while (l < r) {
        int m = (l + r) / 2;
        if (A[ids[m]] > total)
          r = m;
        else
          l = m + 1;
      }
      int cnt_strict_greater = l;
      if (cnt_strict_greater < M) {
        answer = 0;
      }
    }

    res[i] = answer;
  }

  for (ll x : res) {
    cout << x << ' ';
  }
  cout << '\n';

  return 0;
}