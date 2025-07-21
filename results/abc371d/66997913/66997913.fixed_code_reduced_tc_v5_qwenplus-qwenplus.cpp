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
  while (q--) {
    int l, r;
    cin >> l >> r;
    // Find first index where x[i] > r
    int rt = lower_bound(x.begin(), x.end(), r + 1) - x.begin();
    // Find first index where x[i] >= l
    int lt = lower_bound(x.begin(), x.end(), l) - x.begin();
    ll ans = s[rt] - s[lt];
    cout << ans << '\n';
  }
  
  return 0;
}