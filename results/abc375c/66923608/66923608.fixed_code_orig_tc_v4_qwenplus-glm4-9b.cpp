#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  int n; cin >> n;
  vector<pair<long long, long long>> points(n);

  long long ans = 0;
  
  for (int i = 0; i < n; ++i) {
    cin >> points[i].first >> points[i].second;
  }

  // Calculate distance from origin to first point
  ans += sqrt(pow(points[0].first, 2) + pow(points[0].second, 2));

  // Calculate distances between consecutive points
  for (int i = 1; i < n; ++i) {
    ans += sqrt(pow(points[i].first - points[i-1].first, 2) + pow(points[i].second - points[i-1].second, 2));
  }

  // Calculate distance from last point back to origin
  ans += sqrt(pow(points[n-1].first, 2) + pow(points[n-1].second, 2));

  cout << fixed << setprecision(12) << ans << endl;
  
  return 0;
}