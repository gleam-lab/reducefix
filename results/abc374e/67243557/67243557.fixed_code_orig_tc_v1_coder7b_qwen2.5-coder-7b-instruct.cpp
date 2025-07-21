#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;
using Graph = vector<vector<int>>;

ll f(vector<int>& a, vector<int>& b, vector<int>& p, vector<int>& q, ll x){
  ll n = a.size();
  ll ans = 0;
  vector<vector<ll>> dp(n+1, vector<ll>(x+1, 1e10));
  dp[0][0] = 0; // i個買う時の最小値
  rep(i,n){
    rep(j,x+1){
      if(j >= a[i])dp[i+1][j] = min(dp[i+1][j], dp[i][j-a[i]] + p[i]);
      if(j >= b[i])dp[i+1][j] = min(dp[i+1][j], dp[i][j-b[i]] + q[i]);
    }
  }

  rep(j,x+1)ans = max(ans, j - dp[n][j]);
  return ans;
}

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n), b(n), p(n), q(n);
  rep(i,n)cin >> a[i] >> p[i] >> b[i] >> q[i];
  ll now; // wの候補
  ll l = 0, r = 10000000000;
  while(r - l > 1){
    now = (r + l)/2;
    ll tmp = 0;
    rep(i,n){
      tmp += f(a, b, p, q, now);
    }
    if(tmp <= x)l = now;
    else r = now;
  }
  cout << l;
	return 0;
}