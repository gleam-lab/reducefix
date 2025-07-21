#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  double total = 0.0;
  int prev_x = 0, prev_y = 0;

  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    total += hypot(static_cast<double>(x - prev_x), static_cast<double>(y - prev_y));
    prev_x = x;
    prev_y = y;
  }

  // Return to origin
  total += hypot(static_cast<double>(prev_x), static_cast<double>(prev_y));

  // Use high precision output
  cout.precision(15);
  cout << fixed << total << endl;

  return 0;
}