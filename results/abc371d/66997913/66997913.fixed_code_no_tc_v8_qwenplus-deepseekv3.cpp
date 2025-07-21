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
  
  // Ensure x is sorted (if not guaranteed by input)
  vector<pair<int, ll>> combined(n);
  for (int i = 0; i < n; i++) {
    combined[i] = {x[i], p[i]};
  }
  sort(combined.begin(), combined.end());
  for (int i = 0; i < n; i++) {
    x[i] = combined[i].first;
    p[i] = combined[i].second;
    s[i+1] = s[i] + p[i];
  }
  
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    if (l > r) {
      cout << 0 << endl;
      continue;
    }
    int lt = lower_bound(x.begin(), x.end(), l) - x.begin();
    int rt = upper_bound(x.begin(), x.end(), r) - x.begin();
    ll ans = s[rt] - s[lt];
    cout << ans << endl;
  }
  return 0;
}