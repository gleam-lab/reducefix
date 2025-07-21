#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e9 + 10;
const ll inf = 1LL << 60;

void solve() {
  int n, k; cin >> n >> k;
  vector<pair<ll, ll>> ab(n);
  for (int i = 0; i < n; i++) cin >> ab[i].first;
  for (int i = 0; i < n; i++) cin >> ab[i].second;
  sort(ab.begin(), ab.end());

  if (k == 1) {
    ll ans = inf;
    for (int i = 0; i < n; i++) {
      ans = min(ans, ab[i].first * ab[i].second);
    }
    cout << ans << '\n';
    return;
  }

  priority_queue<ll> pq;
  ll sum = 0;
  for (int i = 0; i < k - 1; i++) {
    pq.push(-ab[i].second); // Using negative values to simulate a max-heap with a priority queue
    sum += ab[i].second;
  }

  ll ans = inf;
  for (int i = k - 1; i < n; i++) {
    auto [a, b] = ab[i];
    ans = min(ans, (sum + b) * a);
    if (-pq.top() > b) { // Extract the maximum element from the priority queue
      sum -= pq.top();
      sum += b;
      pq.pop();
      pq.push(-b); // Insert the new maximum element
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;  cin >> t;
  while (t--) solve();
}