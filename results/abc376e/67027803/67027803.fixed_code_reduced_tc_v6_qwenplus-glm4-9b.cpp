#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e9 + 10;
const ll inf = 1LL << 60;

void solve() {
  int n, k; cin >> n >> k;
  vector<pair<ll, ll>> ab(n);
  for (int i = 0; i < n; i++) cin >> ab[i].first;
  for (int i = 0; i < n; i++) cin >> ab[i].second;
  // Sort by A_i descending to maximize A_i in the subset
  sort(ab.begin(), ab.end(), greater<pair<ll, ll>>());

  // Priority queue to minimize the sum of B_i in the subset
  priority_queue<ll, vector<ll>, greater<ll>> q;
  ll sum = 0;

  // Precompute the sum of the largest k-1 B_i values
  for (int i = 0; i < k - 1; i++) {
    q.push(ab[i].second);
    sum += ab[i].second;
  }

  ll ans = inf;
  // Iterate over the remaining elements
  for (int i = k - 1; i < n; i++) {
    auto [a, b] = ab[i];
    // Calculate the potential answer using the maximum B_i in the subset
    ans = min(ans, (sum + b) * a);
    // If the current B_i is smaller than the smallest in the subset, replace it
    if (!q.empty() && b < q.top()) {
      sum += b - q.top();
      q.pop();
      q.push(b);
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