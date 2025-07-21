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
    s[i + 1] = s[i] + p[i];
  }
  
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    // Ensure l and r are within the bounds of the array
    if (l < x[0]) l = x[0];
    if (r > x.back()) r = x.back();
    
    int rt = upper_bound(x.begin(), x.end(), r) - x.begin();
    int lt = lower_bound(x.begin(), x.end(), l) - x.begin();
    
    // Ensure the indices are within the bounds of the prefix sum array
    if (lt < 0) lt = 0;
    if (rt >= n) rt = n - 1;
    
    ll ans = s[rt + 1] - s[lt];
    cout << ans << endl;
  }
  return 0;
}