#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define eb emplace_back

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N, K;
  cin >> N >> K;
  vi A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  // We will use a sliding window approach to keep K elements
  // So we need to remove N-K elements
  int window_size = N - K;
  
  // We want the minimum possible value of max(B) - min(B)
  // where B is any subsequence of length K with elements in original order
  // Since the order must be preserved, we cannot sort

  // The idea: slide a window of size window_size over the array
  // For each window, compute max and min in O(1) using monotonic queues
  // We'll use two monotonic deques to track min and max in sliding window

  deque<int> min_deq;
  deque<int> max_deq;
  int res = INT_MAX;

  for (int r = 0; r < N; ++r) {
    // Maintain min_deq (will have smallest at front)
    while (!min_deq.empty() && A[min_deq.back()] >= A[r]) {
      min_deq.pop_back();
    }
    min_deq.push_back(r);

    // Maintain max_deq (will have largest at front)
    while (!max_deq.empty() && A[max_deq.back()] <= A[r]) {
      max_deq.pop_back();
    }
    max_deq.push_back(r);

    // Remove elements out of window
    while (min_deq.front() <= r - window_size) {
      min_deq.pop_front();
    }
    while (max_deq.front() <= r - window_size) {
      max_deq.pop_front();
    }

    // Once window is valid, update result
    if (r >= window_size - 1) {
      res = min(res, A[max_deq.front()] - A[min_deq.front()]);
    }
  }

  cout << res << endl;
  return 0;
}