#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  // We will use a sliding window of size (N - K) to find the minimum difference
  // between max and min in any subsequence of length (N - K)
  deque<int> min_deq, max_deq;
  int res = numeric_limits<int>::max();

  for (int i = 0; i < N; ++i) {
    // Maintain deque for min
    while (!min_deq.empty() && A[min_deq.back()] >= A[i]) min_deq.pop_back();
    min_deq.push_back(i);
    // Maintain deque for max
    while (!max_deq.empty() && A[max_deq.back()] <= A[i]) max_deq.pop_back();
    max_deq.push_back(i);

    // Remove elements out of window [i-(N-K)+1, i]
    while (min_deq.front() <= i - (N - K)) min_deq.pop_front();
    while (max_deq.front() <= i - (N - K)) max_deq.pop_front();

    // Once we have processed at least (N-K) elements
    if (i >= (N - K - 1)) {
      res = min(res, A[max_deq.front()] - A[min_deq.front()]);
    }
  }

  cout << res << endl;
  return 0;
}