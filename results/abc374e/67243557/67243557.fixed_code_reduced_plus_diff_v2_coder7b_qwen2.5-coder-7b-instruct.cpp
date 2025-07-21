#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;
using Graph = vector<vector<int>>;

ll f(ll a, ll b, ll p, ll q, ll x){
  ll z = x;
  ll ans = 0;
  ll pq = min(p,q);
  vector<ll> dp(10010,1e10);
  dp[0] = 0; // i個買う時の最小値
  rep(i,10010){
    if(i - a >= 0)dp[i] = min(dp[i], dp[i-a] + p);
    if(i - b >= 0)dp[i] = min(dp[i], dp[i-b] + q);
  }
  rep(i,10009)dp[10008-i] = min(dp[10008-i], dp[10009-i]);
  
  ll tt = a*b;
  ll t = (ll)(x/tt);
  ans += dp[tt]*t;
  x %= tt;
  ans += dp[x];
  return ans;
}

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n), b(n), p(n), q(n);
  rep(i,n)cin >> a[i] >> p[i] >> b[i] >> q[i];
  ll now; // wの候補
  ll l = 0, r = 10000000000LL;
  while(r - l > 1){
    now = (r + l)/2;
    ll tmp = 0;
    rep(i,n){
      tmp += f(a[i], b[i], p[i], q[i], now);
    }
    if(tmp <= x)l = now;
    else r = now;
  }
  cout << l;
  return 0;
}