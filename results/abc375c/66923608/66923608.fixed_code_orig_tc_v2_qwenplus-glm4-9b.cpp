#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

double Euclid(double x1, double y1, double x2, double y2){
  double A = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
  return A;
}

int main() {
  int n; cin >> n;
  double ans = 0;
  
  vector<int> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];
  
  // Calculate the distance from the origin to the first point and from the last point back to the origin
  ans += Euclid(0, 0, x[0], y[0]);
  ans += Euclid(x[n-1], y[n-1], 0, 0);
  
  // Calculate the distance between consecutive points
  for (int i = 0; i < n-1; i++) {
    ans += Euclid(x[i], y[i], x[i+1], y[i+1]);
  }
  
  cout << fixed << setprecision(12) << ans << endl;
}