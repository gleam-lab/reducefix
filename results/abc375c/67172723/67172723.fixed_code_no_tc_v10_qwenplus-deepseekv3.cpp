#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  
  int px = 0, py = 0; // previous coordinates, initialized to origin
  double ans = 0;
  
  for(int i = 0; i < n; i++){
    int x, y;
    cin >> x >> y;
    ans += hypot(x - px, y - py); // add distance from previous to current point
    px = x; // update previous coordinates
    py = y;
  }
  
  ans += hypot(px, py); // add distance from last point back to origin
  printf("%.10f\n", ans);
  return 0;
}