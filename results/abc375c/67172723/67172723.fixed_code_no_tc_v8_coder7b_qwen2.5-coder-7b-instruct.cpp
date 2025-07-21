#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  
  long long px=0, py=0; // Changed int to long long to handle large numbers
  double ans=0;
  int x, y;
  for(int i=0; i<n; i++){
    cin >> x >> y;
    ans += hypot(x-px, y-py); // Calculate distance from previous point to current point
    px = x; // Update previous x-coordinate
    py = y; // Update previous y-coordinate
  }
  
  ans += hypot(px, py); // Add distance from last visited point back to origin
  printf("%.10f\n", ans);
  return 0;
}