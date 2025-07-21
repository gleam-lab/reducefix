#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

double EuclideanDistance(int x1, int x2, int y1, int y2 ){
  // Ensure that the inputs are integers as per problem constraints
  double dx = static_cast<double>(x1 - x2);
  double dy = static_cast<double>(y1 - y2);
  double distance = sqrt(dx * dx + dy * dy);
  return distance;
}

int main() {
  int n; cin >> n;
  double ans = 0; 
  vector<int> x(n), y(n);
  
  // Read coordinates into vectors
  rep(i, n) cin >> x[i] >> y[i];
  
  // Calculate the total cost of visiting all points in order and returning to the origin
  rep(i, n) {
    ans += EuclideanDistance(x[i], x[(i + 1) % n], y[i], y[(i + 1) % n]);
  }
  
  cout << fixed << setprecision(12) << ans << endl;
}