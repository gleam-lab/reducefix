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

  // If we need to keep only one element, the difference is 0
  if (m == 1) {
    cout << 0 << endl;
    return 0;
  }

  // Sort the array to consider smallest possible ranges
  sort(a.begin(), a.end());

  int min_diff = numeric_limits<int>::max();

  // Try every window of size m in the sorted array
  for (int i = 0; i + m - 1 < n; i++) {
    min_diff = min(min_diff, a[i + m - 1] - a[i]);
  }

  cout << min_diff << endl;
}