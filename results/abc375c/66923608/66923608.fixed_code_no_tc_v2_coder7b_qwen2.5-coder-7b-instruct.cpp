#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

// Corrected function signature to use integer inputs instead of doubles
long long Euclid(long long x1, long long x2, long long y1, long long y2 ){
  // Calculate the squared distance to avoid floating-point inaccuracies
  long long dx = x1 - x2;
  long long dy = y1 - y2;
  return dx * dx + dy * dy;
}

int main() {
  int n; cin >> n;
  long long ans = 0; 
  vector<long long> x(n), y(n);
  rep(i,n) cin >> x[i] >> y[i];
  
  // No need to push back the first element since we calculate distances between consecutive elements
  
  rep(i,n){
    // Calculate the Euclidean distance using the corrected function
    ans += Euclid(x[i], x[(i + 1) % n], y[i], y[(i + 1) % n]);
  }
  
  // Since we're dealing with squared distances, take the square root at the end
  cout << fixed << setprecision(12) << sqrt(ans) << endl;
}