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
  sort(ab.begin(), ab.end());

  if (k == 1) {
    ll ans = inf;
    for (auto& [a, b]: ab) {
      ans = min(ans, a * b);
    }
    cout << ans << '\n';
    return;
  }

  priority_queue<ll> pq;
  ll sum = 0;
  for (int i=0; i<k-1; i++) {
    pq.push(-ab[i].second);
    sum += ab[i].second;
  }

  ll ans = inf;
  for (int i=k-1; i<n; i++) {
    auto [a, b] = ab[i];
    ll cur = sum + b;
    ans = min(ans, a * cur);

    if (!pq.empty() && -pq.top() > b) {
      sum -= -pq.top();
      sum += b;
      pq.pop();
      pq.push(-b);
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t = 1;  cin >> t;
  while (t--) solve();
}