#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  
  long long px=0, py=0; // Changed int to long long to handle larger values
  double ans=0;
  long long x, y; // Changed int to long long to handle larger values
  for(int i=0; i<n; i++){
    cin >> x >> y;
    ans += hypot(px, py); // Calculate distance from current position to the next point
    px = x; // Update previous x-coordinate
    py = y; // Update previous y-coordinate
  }
  
  ans += hypot(px, py); // Calculate distance from last visited point back to the origin
  printf("%.10f\n", ans);
  return 0;
}