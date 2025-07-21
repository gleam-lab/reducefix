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
    // Adjust indices to be zero-based for lower_bound and upper_bound
    int lt = lower_bound(x.begin(), x.end(), l) - x.begin();
    int rt = upper_bound(x.begin(), x.end(), r) - x.begin() - 1;
    
    if (lt > rt) {
      cout << "0" << endl; // No elements in range [l, r]
    } else {
      int ans = s[rt + 1] - s[lt];
      cout << ans << endl;
    }
  }
  return 0;
}