#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;
using Graph = vector<vector<int>>;

ll f(vector<int>& a, vector<int>& b, vector<int>& p, vector<int>& q, ll x){
  ll n = a.size();
  ll ans = 0;
  vector<ll> dp(x+1, LLONG_MAX);
  dp[0] = 0;
  
  rep(i,n){
    vector<ll> ndp(x+1, LLONG_MAX);
    rep(j,x+1){
      if(j >= a[i])ndp[j] = min(ndp[j], dp[j-a[i]] + p[i]);
      if(j >= b[i])ndp[j] = min(ndp[j], dp[j-b[i]] + q[i]);
    }
    dp = ndp;
  }

  rep(i,x+1)if(dp[i] != LLONG_MAX)return i;
  return -1;
}

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n), b(n), p(n), q(n);
  rep(i,n)cin >> a[i] >> p[i] >> b[i] >> q[i];
  ll now;
  ll l = 0, r = x + 1;
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