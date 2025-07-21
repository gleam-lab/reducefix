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
    ll ans = 0;
    for (int i=0; i<n; i++) {
      ans = max(ans, ab[i].first * ab[i].second);
    }
    cout << ans << '\n';
    return;
  }

  ll ans = INF;
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
  ll sum_b = 0;
  for (int i=0; i<n; i++) {
    if (i < k - 1) {
      pq.push({ab[i].second, i});
      sum_b += ab[i].second;
    } else if (pq.top().first < ab[i].second) {
      sum_b += ab[i].second - pq.top().first;
      pq.pop();
      pq.push({ab[i].second, i});
    }
  }

  for (int i=0; i<n; i++) {
    if (pq.empty()) break;
    ll max_a = ab[pq.top().second].first;
    ans = min(ans, max_a * sum_b);
    sum_b -= pq.top().first;
    pq.pop();
  }

  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  while (t--) solve();
}