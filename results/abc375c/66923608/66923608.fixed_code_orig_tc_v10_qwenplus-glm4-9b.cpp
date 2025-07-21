#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

double Euclid(double x1, double x2, double y1, double y2){
  double dx = x2 - x1;
  double dy = y2 - y1;
  return sqrt(dx * dx + dy * dy);
}

int main() {
  int n; cin >> n;
  double ans = 0;

  vector<double> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }

  // Adding origin to the end of the route
  x.push_back(0);
  y.push_back(0);

  for (int i = 0; i < n; i++) {
    ans += Euclid(x[i], x[i+1], y[i], y[i+1]);
  }

  cout << fixed << setprecision(12) << ans << endl;
}