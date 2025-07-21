#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e9 + 10;
const ll inf = 1LL << 60;

void solve() {
  int n, k; cin >> n >> k;
  vector<ll> a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];

  // Sort arrays
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  // Select the smallest K elements from B and largest K elements from A
  ll sum_b = accumulate(b.begin(), b.begin() + k, 0LL);
  ll max_a = a[n - 1];
  ll result = max_a * sum_b;

  // Check if we can improve the result by including one more element from A
  if (k < n) {
    ll new_sum_b = sum_b - b[k - 1] + b[k];
    ll new_max_a = a[n - 2];
    ll new_result = new_max_a * new_sum_b;
    result = min(result, new_result);
  }

  cout << result << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1; cin >> t;
  while (t--) solve();
}