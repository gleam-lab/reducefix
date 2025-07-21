#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  
  int px = 0, py = 0;
  double ans = 0;
  int x = 0, y = 0; // Initialize to avoid any undefined behavior
  
  for(int i = 0; i < n; i++){
    cin >> x >> y;
    ans += hypot(x - px, y - py);
    px = x;
    py = y;
  }
  
  ans += hypot(x, y); // Distance from last point back to origin
  printf("%.10f\n", ans);
  return 0;
}