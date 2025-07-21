#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;
using Graph = vector<vector<int>>;

ll f(vector<pair<ll,ll>>& v, ll x){
  ll ans = 0;
  sort(v.begin(),v.end());
  ll sum = 0;
  for(auto [a,b]:v){
    sum += a;
    ans += b * max(0LL,x-sum);
  }
  return ans;
}

int main() {
  int n, x;
  cin >> n >> x;
  vector<pair<ll,ll>> s(n), t(n);
  rep(i,n)cin >> s[i].first >> s[i].second >> t[i].first >> t[i].second;
  ll now; // wの候補
  ll l = 0, r = 10000000000;
  while(r - l > 1){
    now = (r + l)/2;
    if(f(s,now) + f(t,now) <= x)l = now;
    else r = now;
  }
  cout << l;
	return 0;
}