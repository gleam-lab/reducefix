#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  
  long long px = 0, py = 0; // Change int to long long to handle large distances accurately
  double ans = 0;
  long long x, y;
  for(int i = 0; i < n; i++){
    cin >> x >> y;
    ans += sqrt((x - px) * (x - px) + (y - py) * (y - py)); // Correctly calculate Euclidean distance using long long arithmetic
    px = x; // Update previous position
    py = y;
  }
  
  ans += sqrt(px * px + py * py); // Correctly calculate distance back to origin
  printf("%.10f\n", ans);
  return 0;
}