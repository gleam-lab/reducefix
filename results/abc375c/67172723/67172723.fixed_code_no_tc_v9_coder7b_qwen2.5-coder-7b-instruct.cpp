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
    ans += hypot(x-px, y-py); // Calculate distance from current position to next point
    px = x; // Update previous x-coordinate
    py = y; // Update previous y-coordinate
  }
  
  ans += hypot(px, py); // Return to origin from last visited point
  printf("%.10f\n", ans);
  return 0;
}