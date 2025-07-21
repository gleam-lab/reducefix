#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e9 + 10;
const ll inf = 1LL << 60;

void solve() {
  int n, k; cin >> n >> k;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];

  // Sort A in descending order and B in ascending order
  sort(a.begin(), a.end(), greater<int>());
  sort(b.begin(), b.end());

  // Initialize variables
  ll ans = inf;
  ll sum_b = 0;
  for (int i = 0; i < k; i++) sum_b += b[i];

  // Sliding window approach
  for (int i = 0; i <= n - k; i++) {
    ll curr_a = a[i];
    ll curr_b_sum = sum_b;
    ans = min(ans, curr_a * curr_b_sum);

    // Update the sum for the next window
    if (i + k < n) {
      sum_b -= b[i];
      sum_b += b[i + k];
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