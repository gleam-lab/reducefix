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
  
  // Sort based on the first element of the pair
  sort(ab.begin(), ab.end());

  // Priority queue to keep track of the sum of B values
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  ll sum = 0;
  for (int i = 0; i < k - 1; i++) {
    pq.push(ab[i].second);
    sum += ab[i].second;
  }

  // Initialize the result with the initial window
  ll ans = inf;
  for (int i = k - 1; i < n; i++) {
    auto [a, b] = ab[i];
    ans = min(ans, (sum + b) * a);
    
    if (!pq.empty()) {
      sum -= pq.top();
      sum += b;
      pq.pop();
      pq.push(b);
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