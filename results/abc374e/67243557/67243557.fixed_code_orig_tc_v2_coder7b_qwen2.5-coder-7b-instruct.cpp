#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;
using Graph = vector<vector<int>>;

ll f(vector<ll>& a, vector<ll>& b, vector<ll>& p, vector<ll>& q, ll x){
  ll ans = 0;
  vector<ll> dp(x+1, LLONG_MAX);
  dp[0] = 0; // i個買う時の最小値
  for(int i = 0; i < a.size(); ++i){
    vector<ll> ndp = dp;
    for(int j = 0; j <= x; ++j){
      if(j - a[i] >= 0)ndp[j] = min(ndp[j], dp[j-a[i]] + p[i]);
      if(j - b[i] >= 0)ndp[j] = min(ndp[j], dp[j-b[i]] + q[i]);
    }
    swap(dp, ndp);
  }
  
  return *min_element(dp.begin(), dp.end());
}

int main() {
  int n, x;
  cin >> n >> x;
  vector<ll> a(n), b(n), p(n), q(n);
  rep(i,n)cin >> a[i] >> p[i] >> b[i] >> q[i];
  ll now; // wの候補
  ll l = 0, r = 10000000000LL;
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