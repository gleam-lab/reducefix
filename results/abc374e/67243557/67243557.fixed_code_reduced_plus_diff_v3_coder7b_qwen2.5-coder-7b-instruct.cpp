#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;
using Graph = vector<vector<int>>;

ll f(vector<int>& a, vector<int>& b, vector<int>& p, vector<int>& q, ll x){
  ll ans = 0;
  vector<ll> dp(x+1, LLONG_MAX);
  dp[0] = 0;
  rep(i,x+1){
    if(i - a[0] >= 0) dp[i] = min(dp[i], dp[i-a[0]] + p[0]);
    if(i - b[0] >= 0) dp[i] = min(dp[i], dp[i-b[0]] + q[0]);
  }
  rep(j,1,n){
    for(int i = x; i >= 0; --i){
      if(i - a[j] >= 0) dp[i] = min(dp[i], dp[i-a[j]] + p[j]);
      if(i - b[j] >= 0) dp[i] = min(dp[i], dp[i-b[j]] + q[j]);
    }
  }
  for(int i = 0; i <= x; ++i){
    if(dp[i] != LLONG_MAX){
      ans = max(ans, i);
    }
  }
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
      tmp += f(a,b,p,q,now);
    }
    if(tmp <= x)l = now;
    else r = now;
  }
  cout << l;
  return 0;
}