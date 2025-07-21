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
  sort(ab.rbegin(), ab.rend()); // Sort in descending order based on A_i to maximize the product
  if (k == 1) {
    ll ans = 0;
    for (int i=0; i<n; i++) {
      ans = max(ans, ab[i].first * ab[i].second);
    }
    cout << ans << '\n';
    return;
  }
  priority_queue<ll> q;
  ll sum = 0;
  for (int i=0; i<k; i++) { // Start with the first k elements
    q.push(ab[i].second);
    sum += ab[i].second;
  }
  ll ans = 0;
  for (int i=k; i<n; i++) {
    auto [a, b] = ab[i];
    ans = max(ans, (sum - q.top() + b) * a); // Adjust the sum by removing the smallest element and adding the current one
    if (q.top() < b) {
      sum -= q.top();
      sum += b;
      q.pop();
      q.push(b);
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