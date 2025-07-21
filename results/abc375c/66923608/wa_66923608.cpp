#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

double Euclid(double x1, double x2, double y1, double y2 ){
  double A = sqrt((x1-x2)*(x1-x2) + (y1- y2)*(y1-y2));
  return A;
}

int main() {
  int n; cin >> n;
  double ans = 0; 
  
  vector<int> x(n), y(n);
  rep(i,n) cin >> x[i] >> y[i];
  x.push_back(x[0]);
  y.push_back(y[0]);
  
  rep(i,n){
    ans += Euclid(x[i],x[i+1],y[i],y[i+1]);
  }
  
  cout << fixed << setprecision(12) << ans << endl;
}
  
  


