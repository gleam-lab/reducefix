#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e9 + 10;
const ll inf = 1LL << 60;

void solve() {
  int n, k; cin >> n >> k;
  vector<pair<ll, ll>> ab(n);
  for (int i = 0; i < n; i++) cin >> ab[i].first >> ab[i].second;
  
  // Sort pairs by A[i] in descending order
  sort(ab.rbegin(), ab.rend());

  // Calculate the sum of the smallest B[i] for the first k elements
  ll sum = 0;
  for (int i = 0; i < k; i++) sum += ab[i].second;

  // Initialize the answer with the current product
  ll ans = sum * ab[k - 1].first;

  // Try replacing the largest element with the next smallest element
  for (int i = k; i < n; i++) {
    sum -= ab[i - k].second;
    sum += ab[i].second;
    ans = min(ans, sum * ab[i].first);
  }

  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;  cin >> t;
  while (t--) solve();
}