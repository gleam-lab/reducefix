#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

  int n;
  cin >> n;
  
  long long px=0, py=0;
  double ans=0;
  long long x, y;
  for(int i=0; i<n; i++){
    cin >> x >> y;
    ans += sqrt((x-px)*(x-px) + (y-py)*(y-py));
    px = x;
    py = y;
  }
  
  ans += sqrt(px*px + py*py);
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}