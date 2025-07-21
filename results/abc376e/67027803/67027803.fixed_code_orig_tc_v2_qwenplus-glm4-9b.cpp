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

  // If k == 1, we can directly take the minimum of A and the sum of B.
  if (k == 1) {
    ll ans = inf;
    for (int i = 0; i < n; ++i) {
      ans = min(ans, ab[i].first * ab[i].second);
    }
    cout << ans << '\n';
    return;
  }

  // Priority queue for A values and their corresponding B sums.
  sort(ab.begin(), ab.end());
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

  ll sum = 0;
  for (int i = 0; i < k - 1; ++i) {
    pq.push({ab[i].first, ab[i].second});
    sum += ab[i].second;
  }

  ll ans = inf;
  while (!pq.empty()) {
    auto [a, b] = pq.top();
    pq.pop();
    ans = min(ans, (sum + b) * a);

    if (!pq.empty()) {
      auto [a2, b2] = pq.top();
      pq.pop();
      pq.push({a, b - b2});
      sum = b2 + a2;
    }
  }

  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1; cin >> t;
  while (t--) solve();
}