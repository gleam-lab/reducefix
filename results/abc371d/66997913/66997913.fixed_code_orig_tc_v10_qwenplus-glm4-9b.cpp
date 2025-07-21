#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;
  vector<ll> x(n), p(n), s(n+1);
  for (ll i = 0; i < n; i++) cin >> x[i];
  for (ll i = 0; i < n; i++) cin >> p[i];
  s[0] = 0;
  for (ll i = 0; i < n; i++) s[i+1] = s[i] + x[i];

  ll q;
  cin >> q;
  for (ll i = 0; i < q; i++) {
    ll l, r;
    cin >> l >> r;
    ll rt = upper_bound(x.begin(), x.end(), r) - x.begin() - 1;
    ll lt = lower_bound(x.begin(), x.end(), l) - x.begin();
    ll ans = s[rt+1] - s[lt];
    cout << ans << endl;
  }
  return 0;
}