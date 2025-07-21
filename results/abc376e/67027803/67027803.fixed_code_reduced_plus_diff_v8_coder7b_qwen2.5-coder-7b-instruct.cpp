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

  // Sort A and B based on their values
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  // Initialize variables for the sliding window
  ll sum_b = 0;
  for (int i = 0; i < k; i++) sum_b += b[i];

  // Initial answer
  ll ans = (ll)a[k - 1] * sum_b;

  // Slide the window across the array
  for (int i = k; i < n; i++) {
    sum_b += b[i] - b[i - k];
    ans = min(ans, (ll)a[i] * sum_b);
  }

  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1; cin >> t;
  while (t--) solve();
}