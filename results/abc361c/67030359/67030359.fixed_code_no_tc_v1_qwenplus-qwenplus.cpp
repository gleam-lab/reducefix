#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef vector<int> vi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, K;
  cin >> N >> K;
  vi A(N);
  for (int i = 0; i < N; ++i) cin >> A[i];

  // Sliding window approach to minimize max-min in a subsequence of size N-K
  // Use deque to maintain min and max in window

  deque<int> min_dq, max_dq;
  ll res = LLONG_MAX;

  for (int i = 0; i < N; ++i) {
    // Maintain min_dq: increasing deque
    while (!min_dq.empty() && A[i] < A[min_dq.back()]) min_dq.pop_back();
    min_dq.push_back(i);

    // Maintain max_dq: decreasing deque
    while (!max_dq.empty() && A[i] > A[max_dq.back()]) max_dq.pop_back();
    max_dq.push_back(i);

    // Remove out-of-window indices
    if (min_dq.front() <= i - (N - K)) min_dq.pop_front();
    if (max_dq.front() <= i - (N - K)) max_dq.pop_front();

    // When window is complete, update result
    if (i >= (N - K - 1)) {
      res = min(res, 1LL * A[max_dq.front()] - A[min_dq.front()]);
    }
  }

  cout << res << endl;
  return 0;
}