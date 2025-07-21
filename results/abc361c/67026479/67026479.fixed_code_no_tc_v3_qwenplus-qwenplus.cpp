#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, m;
  cin >> n >> k;
  vector<int> a(n);
  m = n - k;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  // We need to select a subsequence of length m with minimum difference
  // between max and min, while preserving the original order.

  // To do this efficiently, we can use sliding window technique.
  // Consider a window of size m in the original array, slide it from left to right,
  // and compute the diff between max and min in each window.

  // Since N is large (up to 2e5), we need an O(N) or O(N log N) solution.
  // We'll use a monotonic deque to maintain min and max in the current window.

  deque<int> minQ, maxQ;
  int res = numeric_limits<int>::max();

  for (int i = 0; i < n; ++i) {
    // Remove elements out of the window
    while (!minQ.empty() && minQ.front() <= i - m)
      minQ.pop_front();
    while (!maxQ.empty() && maxQ.front() <= i - m)
      maxQ.pop_front();

    // Add new element to the deques
    while (!minQ.empty() && a[minQ.back()] >= a[i])
      minQ.pop_back();
    while (!maxQ.empty() && a[maxQ.back()] <= a[i])
      maxQ.pop_back();

    minQ.push_back(i);
    maxQ.push_back(i);

    // Once the window is full, update result
    if (i >= m - 1) {
      res = min(res, a[maxQ.front()] - a[minQ.front()]);
    }
  }

  cout << res << endl;
}