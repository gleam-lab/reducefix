#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;
using Graph = vector<vector<int>>;

ll f(vector<ll>& a, vector<ll>& b, vector<ll>& p, vector<ll>& q, ll x){
  ll ans = 0;
  for(int i = 0; i < a.size(); i++){
    ll pa = a[i], pb = b[i], pp = p[i], pq = q[i];
    ll min_cost = 1e18;
    if(pa != 0)min_cost = min(min_cost, (x / pa) * pp);
    if(pb != 0)min_cost = min(min_cost, (x / pb) * pq);
    if(x % pa == 0)min_cost = min(min_cost, ((x / pa) - 1) * pp);
    if(x % pb == 0)min_cost = min(min_cost, ((x / pb) - 1) * pq);
    ans += min_cost;
  }
  return ans;
}

int main() {
  int n, x;
  cin >> n >> x;
  vector<ll> a(n), b(n), p(n), q(n);
  rep(i,n)cin >> a[i] >> p[i] >> b[i] >> q[i];
  ll now; // wの候補
  ll l = 0, r = 10000000000;
  while(r - l > 1){
    now = (r + l)/2;
    ll tmp = f(a, b, p, q, now);
    if(tmp <= x)l = now;
    else r = now;
  }
  cout << l;
	return 0;
}