#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;

ll f(ll a, ll b, ll p, ll q, ll x){
  ll dp[10010] = {1e9};
  dp[0] = 0;
  for(int i=0; i<10010; i++){
    if(i >= a) dp[i] = min(dp[i], dp[i - a] + p);
    if(i >= b) dp[i] = min(dp[i], dp[i - b] + q);
  }
  for(int i=10009; i>=0; i--) dp[i] = min(dp[i], dp[i + 1]);

  ll tt = a * b;
  ll t = (x + tt - 1) / tt; // Ceiling division
  ll rem = x - t * tt;
  ll ans = dp[tt] * t + dp[rem];
  return ans;
}

int main() {
  int n, x;
  cin >> n >> x;
  vector<ll> a(n), b(n), p(n), q(n);
  rep(i,n) cin >> a[i] >> p[i] >> b[i] >> q[i];
  ll now; // wã®åè£
  ll l = 0, r = 1e9;
  while(r - l > 1){
    now = (r + l) / 2;
    ll tmp = 0;
    rep(i,n) tmp += f(a[i], b[i], p[i], q[i], now);
    if(tmp <= x) l = now;
    else r = now;
  }
  cout << l;
  return 0;
}