#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

double Euclid(double x1, double y1, double x2, double y2){
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
  int n; cin >> n;
  double ans = 0;
  
  vector<int> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];
  
  // Close the loop by duplicating the first point at the end
  x.push_back(x[0]);
  y.push_back(y[0]);
  
  rep(i, n){
    // Sum the distance between the current point and the next point
    ans += Euclid(x[i], y[i], x[i + 1], y[i + 1]);
  }
  
  // Finally, add the distance from the last point to the origin
  ans += Euclid(x[n], y[n], x[0], y[0]);
  
  cout << fixed << setprecision(12) << ans << endl;
  
  return 0;
}