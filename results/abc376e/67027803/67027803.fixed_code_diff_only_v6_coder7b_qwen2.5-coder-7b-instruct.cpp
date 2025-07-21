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
  sort(ab.rbegin(), ab.rend()); // Sort in descending order to maximize the product when selecting elements for S
  ll max_a = 0;
  ll sum_b = 0;
  for (int i=0; i<k; i++) {
    max_a = max(max_a, ab[i].first);
    sum_b += ab[i].second;
  }
  ll ans = max_a * sum_b;
  for (int i=k; i<n; i++) {
    if (ab[i].second < ab[k-1].second) { // If current B_i is smaller than the smallest B_i in the selected set
      sum_b -= ab[i-k].second; // Remove the smallest B_i from the sum
      sum_b += ab[i].second; // Add the current B_i to the sum
      ans = min(ans, max_a * sum_b); // Update the answer with the new product
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