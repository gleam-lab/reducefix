#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  
  int px = 0, py = 0;
  double ans = 0;
  int x = 0, y = 0; // Initialize to origin, will be updated in the loop
  
  for(int i = 0; i < n; i++){
    cin >> x >> y;
    ans += hypot(x - px, y - py);
    px = x;
    py = y;
  }
  
  // Add distance from the last point back to the origin
  ans += hypot(x, y);
  printf("%.10f\n", ans);
  return 0;
}