#include <bits/stdc++.h>
using namespace std;

// Function to calculate Euclidean distance between two points
double Euclid(int x1, int x2, int y1, int y2) {
  long long dx = (long long)x1 - x2;
  long long dy = (long long)y1 - y2;
  return sqrt(dx * dx + dy * dy);
}

int main() {
  int n; cin >> n;
  double ans = 0; 

  // Vectors to store coordinates
  vector<int> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];

  // Calculate the total cost of visiting all points and returning to the origin
  rep(i, n) {
    ans += Euclid(x[i], x[(i + 1) % n], y[i], y[(i + 1) % n]);
  }

  cout << fixed << setprecision(12) << ans << endl;
}