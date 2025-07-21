#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;
using Graph = vector<vector<int>>;

ll f(vector<pair<pair<ll,ll>,pair<ll,ll>>> &v, ll x, ll n){
  ll ans = 0;
  vector<ll> dp(x+1,1e10);
  dp[0] = 0; // i個買う時の最小値
  for(auto [a,b]: v){
    ll c = a.first, d = a.second, e = b.first, f = b.second;
    for(int i=x;i>=0;i--){
      if(i-c>=0)dp[i] = min(dp[i], dp[i-c]+e);
      if(i-d>=0)dp[i] = min(dp[i], dp[i-d]+f);
    }
  }
  for(int i=0;i<=x;i++){
    if(dp[i]<=x)ans = max(ans,i);
  }
  return ans;
}

int main() {
  int n, x;
  cin >> n >> x;
  vector<pair<pair<ll,ll>,pair<ll,ll>>> v(n);
  rep(i,n)cin >> v[i].first.first >> v[i].second.first >> v[i].first.second >> v[i].second.second;
  ll ans = 0;
  ans = f(v,x,n);
  cout << ans;
	return 0;
}