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

  ll total_current = accumulate(A.begin(), A.end(), 0LL);
  ll remaining_votes = K - total_current;

  vector<ll> sorted_A = A;
  sort(sorted_A.begin(), sorted_A.end());

  vector<ll> suffix_sum(N + 1);
  for (int i = N - 1; i >= 0; --i) {
    suffix_sum[i] = suffix_sum[i + 1] + sorted_A[i];
  }

  vector<ll> result(N);

  for (int i = 0; i < N; ++i) {
    ll current = A[i];

    // Binary search on minimum additional votes needed
    ll low = 0, high = remaining_votes;
    ll answer = -1;

    while (low <= high) {
      ll mid = (low + high) / 2;
      ll target = current + mid;

      // Find how many candidates have strictly more votes than target in the sorted list
      int idx = lower_bound(sorted_A.begin(), sorted_A.end(), target + 1) - sorted_A.begin();
      int count_greater = N - idx;

      // We need to ensure that at most M-1 candidates have more votes than this candidate
      if (count_greater < M) {
        answer = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    if (answer == 0 && current + remaining_votes < target) {
      // If we don't need any additional votes but must still check if they can win with zero
      int idx = lower_bound(sorted_A.begin(), sorted_A.end(), current + remaining_votes + 1) - sorted_A.begin();
      int count_greater = N - idx;
      if (count_greater >= M) {
        result[i] = -1;
      } else {
        result[i] = 0;
      }
    } else if (answer != -1) {
      result[i] = answer;
    } else {
      // Check if even after using all remaining votes, can't get into top M
      ll final_score = current + remaining_votes;
      int idx = lower_bound(sorted_A.begin(), sorted_A.end(), final_score + 1) - sorted_A.begin();
      int count_greater = N - idx;
      result[i] = (count_greater < M) ? remaining_votes : -1;
    }
  }

  for (int i = 0; i < N; ++i) {
    cout << max(result[i], -1LL) << " ";
  }

  return 0;
}