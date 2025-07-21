#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;
using Graph = vector<vector<int>>;

ll f(vector<int>& a, vector<int>& b, vector<int>& p, vector<int>& q, ll x){
  ll ans = 0;
  for(int i = 0; i < a.size(); ++i){
    ll max_cost = max(p[i], q[i]);
    ll min_cost = min(p[i], q[i]);
    ll cost = min_cost * (x / (a[i] + b[i]));
    x -= cost / min_cost * (a[i] + b[i]);
    ans += cost;
  }
  return ans;
}

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n), b(n), p(n), q(n);
  rep(i,n)cin >> a[i] >> p[i] >> b[i] >> q[i];
  ll l = 0, r = 10000000000LL;
  while(r - l > 1){
    ll mid = (l + r) / 2;
    if(f(a, b, p, q, mid) <= x) l = mid;
    else r = mid;
  }
  cout << l;
  return 0;
}