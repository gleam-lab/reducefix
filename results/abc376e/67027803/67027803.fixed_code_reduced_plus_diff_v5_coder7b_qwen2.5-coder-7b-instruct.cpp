#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e9 + 10;
const ll inf = 1LL<<60;

void solve() {
  int n, k; cin >> n >> k;
  vector<pair<ll, ll>> ab(n);
  for (int i=0; i<n; i++) cin >> ab[i].first;
  for (int i=0; i<n; i++) cin >> ab[i].second;
  sort(ab.rbegin(), ab.rend());

  ll ans = inf;
  for (int i=0; i<=n-k; i++) {
    ans = min(ans, (ab[i].first * accumulate(begin(ab)+i, begin(ab)+min(i+k,n), 0LL)));
  }

  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t = 1;  cin >> t;
  while (t--) solve();
}