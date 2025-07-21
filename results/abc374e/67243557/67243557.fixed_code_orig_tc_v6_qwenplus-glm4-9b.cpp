#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
using ll = long long;

ll f(ll a, ll b, ll p, ll q, ll x) {
  ll dp[10010];
  memset(dp, 1e10, sizeof(dp));
  dp[0] = 0;
  for (ll i = 1; i <= 10009; i++) {
    if (i - a >= 0) dp[i] = min(dp[i], dp[i - a] + p);
    if (i - b >= 0) dp[i] = min(dp[i], dp[i - b] + q);
  }
  reverse(dp, dp + 10010);
  ll z = x, ans = 0, pq = min(p, q);
  ll t = x / (a * b), r = a * b;
  ans += dp[r] * t;
  z %= r;
  ans += dp[z];
  return ans;
}

int main() {
  ll n, x;
  cin >> n >> x;
  vector<ll> a(n), b(n), p(n), q(n);
  rep(i, n) cin >> a[i] >> p[i] >> b[i] >> q[i];
  ll now, l = 0, r = 10000000000;
  while (r - l > 1) {
    now = (l + r) / 2;
    ll tmp = 0;
    rep(i, n) tmp += f(a[i], b[i], p[i], q[i], now);
    if (tmp <= x) l = now;
    else r = now;
  }
  cout << l << endl;
  return 0;
}