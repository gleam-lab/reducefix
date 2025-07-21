#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

// Function to calculate Euclidean distance between two points
double Euclid(int x1, int x2, int y1, int y2) {
  return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
  int n; cin >> n;
  double ans = 0; 
  
  // Vectors to store the coordinates of the points
  vector<int> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];
  
  // Calculate the total cost of moving from one point to the next
  rep(i, n) {
    ans += Euclid(x[i], x[(i + 1) % n], y[i], y[(i + 1) % n]);
  }
  
  // Print the result with high precision
  cout << fixed << setprecision(12) << ans << endl;
}