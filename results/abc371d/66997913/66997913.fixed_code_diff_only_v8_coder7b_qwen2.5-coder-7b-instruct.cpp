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
    auto it_r = upper_bound(x.begin(), x.end(), r);
    auto it_l = lower_bound(x.begin(), x.end(), l);
    if (it_r == x.begin() || it_l == x.end()) continue; // Check for valid range
    int rt = it_r - x.begin() - 1;
    int lt = it_l - x.begin();
    int ans = s[rt + 1] - s[lt];
    cout << ans << endl;
  }
  return 0;
}