#include <bits/stdc++.h>
using namespace std;

double EuclideanDistance(int x1, int y1, int x2, int y2) {
  double dx = static_cast<double>(x1 - x2);
  double dy = static_cast<double>(y1 - y2);
  return sqrt(dx * dx + dy * dy);
}

int main() {
  int n; cin >> n;
  vector<int> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];

  double totalCost = 0;
  for (int i = 0; i < n; ++i) {
    totalCost += EuclideanDistance(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
  }

  cout << fixed << setprecision(12) << totalCost << endl;
  return 0;
}