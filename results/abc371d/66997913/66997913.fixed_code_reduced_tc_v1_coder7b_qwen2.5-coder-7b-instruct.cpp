#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; i++) cin >> x[i];
  vector<ll> p(n), s(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    s[i + 1] = s[i] + p[i];
  }

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    auto it_l = lower_bound(x.begin(), x.end(), l);
    auto it_r = upper_bound(x.begin(), x.end(), r);
    if (it_l == x.end() || *it_l > r) it_l--;
    if (it_r == x.begin() || *prev(it_r) < l) it_r++;
    int idx_l = distance(x.begin(), it_l);
    int idx_r = distance(x.begin(), prev(it_r));
    ll ans = s[idx_r + 1] - s[idx_l];
    cout << ans << endl;
  }

  return 0;
}