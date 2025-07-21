#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  long long px = 0, py = 0;
  double ans = 0.0;
  long long x, y;

  vector<pair<long long, long long>> points(n);
  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    points[i] = {x, y};
  }

  // From origin to first point
  ans += hypot(points[0].first - 0.0, points[0].second - 0.0);

  // Between consecutive points
  for (int i = 1; i < n; ++i) {
    ans += hypot(points[i].first - points[i-1].first, points[i].second - points[i-1].second);
  }

  // From last point back to origin
  ans += hypot(points[n-1].first - 0.0, points[n-1].second - 0.0);

  // Print with sufficient precision
  cout.precision(15);
  cout << fixed << ans << endl;

  return 0;
}