#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, m;
  cin >> n >> k;
  m = n - k;

  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  // We need to find the minimum possible (max - min)
  // over all contiguous subsequences of length m
  // because removing K elements is equivalent to selecting
  // a contiguous subarray of length m in original array

  int min_diff = numeric_limits<int>::max();
  multiset<int> window;

  // Initialize first window
  for (int i = 0; i < m; ++i) {
    window.insert(a[i]);
  }

  for (int i = 0; i <= n - m; ++i) {
    // Compute current window's diff
    min_diff = min(min_diff, *window.rbegin() - *window.begin());

    // Move window forward if not last iteration
    if (i < n - m) {
      window.erase(window.find(a[i]));       // Remove the outgoing element
      window.insert(a[i + m]);              // Add the new element
    }
  }

  cout << min_diff << endl;
}