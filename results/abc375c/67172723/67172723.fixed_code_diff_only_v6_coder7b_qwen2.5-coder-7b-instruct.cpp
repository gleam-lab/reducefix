#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  long long px = 0, py = 0;
  double ans = 0;
  long long x, y;
  
  // Calculate the total distance from the origin to each point and back to the origin
  for(int i = 0; i <= n; i++) {
    if(i == n) {
      x = 0, y = 0; // Return to the origin
    } else {
      cin >> x >> y; // Read the next point
    }
    ans += sqrt((x - px) * (x - px) + (y - py) * (y - py));
    px = x;
    py = y;
  }
  
  printf("%.10f\n", ans);
  return 0;
}