#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, m;
  cin >> n >> k;
  m = n - k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  // If we can only keep one element, the difference is zero
  if (m == 1) {
    cout << 0 << endl;
    return 0;
  }

  vector<int> sorted_a = a;
  sort(sorted_a.begin(), sorted_a.end());

  long long min_diff = 1e18;
  for (int i = 0; i + m - 1 < n; ++i) {
    long long diff = sorted_a[i + m - 1] - sorted_a[i];
    min_diff = min(min_diff, diff);
  }

  cout << min_diff << endl;
}