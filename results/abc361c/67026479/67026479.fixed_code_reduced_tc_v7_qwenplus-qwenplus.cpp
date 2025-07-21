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

  // If we need to select only one element, the difference is zero
  if (m == 1) {
    cout << 0 << endl;
    return 0;
  }

  vector<int> sorted_a = a;
  sort(sorted_a.begin(), sorted_a.end());

  long long min_diff = 1e18;
  for (int i = 0; i + m - 1 < n; i++) {
    long long diff = sorted_a[i + m - 1] - sorted_a[i];
    min_diff = min(min_diff, diff);
  }

  cout << min_diff << endl;
}