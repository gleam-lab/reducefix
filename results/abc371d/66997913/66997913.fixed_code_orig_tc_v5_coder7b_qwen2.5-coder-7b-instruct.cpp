#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; i++) cin >> x[i];
  sort(x.begin(), x.end());
  vector<ll> s(n + 1);
  for (int i = 0; i < n; i++) s[i + 1] = s[i] + x[i];

  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    auto it_l = lower_bound(x.begin(), x.end(), l);
    auto it_r = upper_bound(x.begin(), x.end(), r);
    int idx_l = it_l - x.begin();
    int idx_r = it_r - x.begin();
    ll ans = s[idx_r] - s[idx_l];
    cout << ans << '\n';
  }
  return 0;
}