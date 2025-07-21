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
    ans += hypot(x-px, y-py);
    px = x;
    py = y;
  }
  
  ans += hypot(px, py); // Correctly update the last position before returning to the origin
  printf("%.10f\n", ans);
  return 0;
}