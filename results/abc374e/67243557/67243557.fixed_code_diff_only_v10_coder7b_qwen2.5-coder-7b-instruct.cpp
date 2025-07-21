#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
using Graph = vector<vector<int>>;

ll f(vector<int>& a, vector<int>& b, vector<int>& p, vector<int>& q, int x){
  int n = a.size();
  vector<ll> dp(x+1, LLONG_MAX); // Initialize dp array with maximum values
  dp[0] = 0; // Base case: no cost to buy zero items

  rep(i, n){
    int ai = a[i], bi = b[i], pi = p[i], qi = q[i];
    for(int j = x; j >= ai && j >= bi; j--){
      dp[j] = min(dp[j], dp[j-ai] + pi);
      dp[j] = min(dp[j], dp[j-bi] + qi);
    }
  }

  ll ans = 0;
  for(int i = 0; i <= x; i++){
    ans = max(ans, dp[i]);
  }
  return ans;
}

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n), b(n), p(n), q(n);
  rep(i,n)cin >> a[i] >> p[i] >> b[i] >> q[i];
  int now; // wの候補
  int l = 0, r = 10000000000;
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