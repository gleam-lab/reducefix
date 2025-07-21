#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
using ll = long long;

ll f(ll a, ll b, ll p, ll q, ll x) {
  ll z = x;
  ll ans = 0;
  ll pq = min(p, q);
  vector<ll> dp(10010, 1e10);
  dp[0] = 0; // iåè²·ãæã®æå°å¤
  rep(i, 10010) {
    if (i - a >= 0) dp[i] = min(dp[i], dp[i - a] + p);
    if (i - b >= 0) dp[i] = min(dp[i], dp[i - b] + q);
  }
  rep(i, 10009) dp[10008 - i] = min(dp[10008 - i], dp[10009 - i]);
  

  ll tt = a * b;
  ll t = (ll)(x / tt);
  ans += dp[tt] * t;
  x %= tt;
  ans += dp[x];
  return ans;
}

int main() {
  int n, x;
  cin >> n >> x;
  vector<pair<int, pair<int, int>>> a(n); // a[i] = {a, b} and cost p, q
  ll p, q;
  rep(i, n) {
    cin >> a[i].first >> a[i].second.first >> a[i].second.second;
    p = a[i].second.first;
    q = a[i].second.second;
  }

  ll now; // wã®åè£
  ll l = 0, r = 1e9;
  while (r - l > 1) {
    now = (r + l) / 2;
    ll tmp = 0;
    rep(i, n) {
      tmp += f(a[i].first, a[i].second.first, p, q, now);
    }
    if (tmp <= x) l = now;
    else r = now;
  }
  cout << l;
  return 0;
}