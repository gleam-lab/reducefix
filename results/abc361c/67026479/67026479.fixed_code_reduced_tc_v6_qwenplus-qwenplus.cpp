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

  sort(a.begin(), a.end());

  int dmin = numeric_limits<int>::max();
  for (int i = 0; i + m - 1 < n; i++) {
    int d = a[i + m - 1] - a[i];
    dmin = min(dmin, d);
  }

  cout << dmin << endl;
}