#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

double Euclid(int x1, int y1, int x2, int y2){
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
  int n; cin >> n;
  vector<pair<int, int>> points(n);
  
  rep(i, n) {
    cin >> points[i].first >> points[i].second;
  }
  
  double total_cost = 0.0;
  
  // Calculate the cost from the origin to the first point
  total_cost += Euclid(0, 0, points[0].first, points[0].second);
  
  // Calculate the cost between consecutive points
  rep(i, n - 1) {
    total_cost += Euclid(points[i].first, points[i].second, points[i + 1].first, points[i + 1].second);
  }
  
  // Calculate the cost from the last point back to the origin
  total_cost += Euclid(points[n - 1].first, points[n - 1].second, 0, 0);
  
  cout << fixed << setprecision(12) << total_cost << endl;
  
  return 0;
}