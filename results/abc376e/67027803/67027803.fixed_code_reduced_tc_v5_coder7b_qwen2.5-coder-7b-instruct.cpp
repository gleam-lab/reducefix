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
  
  // Sort by A_i in ascending order
  sort(ab.begin(), ab.end());

  // Priority queue to keep track of B_i values in the current window
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  ll sum_b = 0;
  
  // Initialize the first window
  for (int i = 0; i < k; i++) {
    pq.push(ab[i].second);
    sum_b += ab[i].second;
  }

  ll ans = inf;
  for (int i = k; i < n; i++) {
    auto [a, b] = ab[i];
    ans = min(ans, a * sum_b);

    // Remove elements from the window until the maximum value is within the allowed range
    while (!pq.empty() && ab[pq.top() - 1].first <= a) {
      sum_b -= ab[pq.top() - 1].second;
      pq.pop();
    }

    pq.push(i + 1);
    sum_b += ab[i].second;
  }

  // Final check for the last window
  ans = min(ans, ab[n - 1].first * sum_b);

  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1; cin >> t;
  while (t--) solve();
}