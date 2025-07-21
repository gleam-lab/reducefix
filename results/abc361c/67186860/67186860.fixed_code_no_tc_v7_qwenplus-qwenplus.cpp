#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
  }

  // We need to remove exactly K elements
  // The remaining array B must have N-K elements
  int len_B = n - k;
  
  // To minimize max(B) - min(B), we want to choose a subsequence of length len_B
  // from A such that the difference between its max and min is minimized

  // Sliding window on sorted values won't work directly because order matters
  // Instead, consider this: Try all windows of size len_B in the original array,
  // compute min and max in each window, and find the one with smallest difference

  // But computing min/max naively per window would be O(N^2) worst case
  // Use deque-based sliding window for efficient min and max tracking

  deque<int> max_deque, min_deque;
  int ans = numeric_limits<int>::max();

  for (int i = 0; i < n; ++i) {
    // Maintain max_deque for sliding window maximum
    while (!max_deque.empty() && A[i] > A[max_deque.back()])
      max_deque.pop_back();
    max_deque.push_back(i);

    // Maintain min_deque for sliding window minimum
    while (!min_deque.empty() && A[i] < A[min_deque.back()])
      min_deque.pop_back();
    min_deque.push_back(i);

    // Remove indices outside of window
    if (i >= len_B) {
      if (max_deque.front() <= i - len_B)
        max_deque.pop_front();
      if (min_deque.front() <= i - len_B)
        min_deque.pop_front();
    }

    // When window is valid, calculate difference
    if (i >= len_B - 1) {
      ans = min(ans, A[max_deque.front()] - A[min_deque.front()]);
    }
  }

  cout << ans << endl;
  return 0;
}