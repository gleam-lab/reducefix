#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;
using Graph = vector<vector<int>>;

ll f(int a, int b, int p, int q, int x){
  vector<ll> dp(x+1, LLONG_MAX); // Initialize dp array with infinity
  dp[0] = 0; // Base case: cost to buy 0 items is 0
  for(int i = 1; i <= x; ++i){
    if(i >= a) dp[i] = min(dp[i], dp[i-a] + p); // Cost to buy one item of type a
    if(i >= b) dp[i] = min(dp[i], dp[i-b] + q); // Cost to buy one item of type b
  }
  return dp[x]; // Minimum cost to buy exactly x items
}

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n), b(n), p(n), q(n);
  rep(i,n)cin >> a[i] >> p[i] >> b[i] >> q[i];
  int now; // w的候補
  int l = 0, r = 10000000000;
  while(r - l > 1){
    now = (r + l) / 2;
    bool possible = true;
    rep(i,n){
      if(f(a[i], b[i], p[i], q[i], now) > x){ // Check if it's possible to buy 'now' items within budget
        possible = false;
        break;
      }
    }
    if(possible) l = now;
    else r = now;
  }
  cout << l;
  return 0;
}