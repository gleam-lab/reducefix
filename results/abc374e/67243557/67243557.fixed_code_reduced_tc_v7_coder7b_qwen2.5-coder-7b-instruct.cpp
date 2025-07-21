#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;
using Graph = vector<vector<int>>;

ll f(const vector<int>& a, const vector<int>& b, const vector<int>& p, const vector<int>& q, ll x){
  ll ans = 0;
  for(int i = 0; i < a.size(); ++i) {
    ll aa = a[i], bb = b[i], pp = p[i], qq = q[i];
    ll pq = min(pp, qq);
    vector<ll> dp(x + 1, LLONG_MAX);
    dp[0] = 0;
    
    for(int j = 0; j <= x; ++j) {
      if(j - aa >= 0) dp[j] = min(dp[j], dp[j-aa] + pp);
      if(j - bb >= 0) dp[j] = min(dp[j], dp[j-bb] + qq);
    }
    
    ans += dp[min(x, aa * bb)];
  }
  
  return ans;
}

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n), b(n), p(n), q(n);
  rep(i,n) cin >> a[i] >> p[i] >> b[i] >> q[i];
  
  ll l = 0, r = 10000000000LL;
  while(r - l > 1) {
    ll m = (l + r) / 2;
    ll total_cost = 0;
    for(int i = 0; i < n; ++i) {
      total_cost += f({a[i]}, {b[i]}, {p[i]}, {q[i]}, m);
    }
    
    if(total_cost <= x) {
      l = m;
    } else {
      r = m;
    }
  }
  
  cout << l << endl;
  return 0;
}