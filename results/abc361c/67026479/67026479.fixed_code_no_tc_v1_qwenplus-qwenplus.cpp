#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, m;
  cin >> n >> k;
  m = n - k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  // If we are left with only one element, the difference is 0
  if (m == 1) {
    cout << 0 << endl;
    return 0;
  }

  // Sliding window to find minimum of max-min over all windows of size m
  deque<int> minQ, maxQ;
  int result = numeric_limits<int>::max();

  for (int i = 0; i < n; ++i) {
    // Maintain increasing deque for min
    while (!minQ.empty() && a[i] < a[minQ.back()]) minQ.pop_back();
    // Maintain decreasing deque for max
    while (!maxQ.empty() && a[i] > a[maxQ.back()]) maxQ.pop_back();

    minQ.push_back(i);
    maxQ.push_back(i);

    // Remove indices outside the current window
    while (!minQ.empty() && minQ.front() <= i - m) minQ.pop_front();
    while (!maxQ.empty() && maxQ.front() <= i - m) maxQ.pop_front();

    // When window is valid, update result
    if (i >= m - 1) {
      result = min(result, a[maxQ.front()] - a[minQ.front()]);
    }
  }

  cout << result << endl;
}