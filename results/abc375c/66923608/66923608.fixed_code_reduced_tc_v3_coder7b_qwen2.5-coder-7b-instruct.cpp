#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

double Euclid(int x1, int x2, int y1, int y2 ) {
  double A = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
  return A;
}

int main() {
  int n; cin >> n;
  double ans = 0; 

  vector<int> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];

  rep(i, n) {
    ans += Euclid(x[i], x[(i + 1) % n], y[i], y[(i + 1) % n]);
  }

  cout << fixed << setprecision(12) << ans << endl;
}