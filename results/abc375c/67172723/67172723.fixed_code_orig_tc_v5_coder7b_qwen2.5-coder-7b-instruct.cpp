#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  double px = 0, py = 0, ans = 0;
  int x, y;
  for(int i = 0; i < n; i++) {
    cin >> x >> y;
    ans += sqrt((x - px)*(x - px) + (y - py)*(y - py));
    px = x, py = y;
  }
  
  ans += sqrt(px*px + py*py); // Return to origin
  printf("%.10f\n", ans);
  return 0;
}