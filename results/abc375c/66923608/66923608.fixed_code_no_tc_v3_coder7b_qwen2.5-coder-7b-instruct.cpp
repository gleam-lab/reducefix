#include <bits/stdc++.h>
using namespace std;

double EuclideanDistance(int x1, int y1, int x2, int y2) {
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> points(n);

  for(int i = 0; i < n; ++i) {
    cin >> points[i].first >> points[i].second;
  }

  double totalCost = 0;

  // Calculate distance between consecutive points
  for(int i = 0; i < n - 1; ++i) {
    totalCost += EuclideanDistance(points[i].first, points[i].second, points[i + 1].first, points[i + 1].second);
  }

  // Add the distance back to the origin
  totalCost += EuclideanDistance(points[n - 1].first, points[n - 1].second, points[0].first, points[0].second);

  cout << fixed << setprecision(12) << totalCost << endl;

  return 0;
}