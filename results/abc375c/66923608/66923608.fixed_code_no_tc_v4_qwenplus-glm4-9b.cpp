#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

double distance(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
  int n; cin >> n;
  vector<pair<double, double>> points(n + 1); // +1 for the return to origin
  
  for (int i = 0; i < n; ++i) {
    cin >> points[i].first >> points[i].second;
  }
  
  double total_cost = 0.0;
  for (int i = 0; i < n; ++i) {
    total_cost += distance(points[i].first, points[i].second, points[i + 1].first, points[i + 1].second);
  }
  
  cout << fixed << setprecision(12) << total_cost << endl;
  
  return 0;
}