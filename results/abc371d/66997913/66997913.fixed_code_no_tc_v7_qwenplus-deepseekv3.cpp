#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; i++) cin >> x[i];
  vector<ll> p(n), s(n+1);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    s[i+1] = s[i] + p[i];
  }
  
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    // Find first x >= l
    int lt = lower_bound(x.begin(), x.end(), l) - x.begin();
    // Find first x > r, then subtract 1 to get last x <= r
    int rt = upper_bound(x.begin(), x.end(), r) - x.begin();
    // Ensure lt and rt are within bounds
    if (lt >= rt) {
      cout << 0 << endl;
    } else {
      cout << s[rt] - s[lt] << endl;
    }
  }
  return 0;
}