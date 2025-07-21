#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  
  int px=0, py=0;
  double ans=0;
  int x, y;
  for(int i=0; i<n; i++){
    cin >> x >> y;
    ans += hypot(x-px, y-py); // Correctly calculate distance between current and previous point
    px = x; // Update previous x-coordinate
    py = y; // Update previous y-coordinate
  }
  
  ans += hypot(px, py); // Calculate distance back to the origin after visiting all points
  printf("%.10f\n", ans);
  return 0;
}