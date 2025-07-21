#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  vector<pair<int, int>> points(n);
  for(int i = 0; i < n; ++i) {
      cin >> points[i].first >> points[i].second;
  }

  double ans = 0;
  for(int i = 1; i < n; ++i) {
      ans += hypot(points[i].first - points[i-1].first, points[i].second - points[i-1].second);
  }

  // Return to origin
  ans += hypot(points[0].first, points[0].second);

  printf("%.10f\n", ans);
  return 0;
}