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
  sort(ab.rbegin(), ab.rend()); // Sort in descending order based on A_i
  ll max_a = ab[k-1].first; // Maximum A_i for any subset of size K
  ll sum_b = accumulate(ab.begin(), ab.begin()+k, 0LL); // Sum of B_i for first K elements
  ll ans = max_a * sum_b; // Initial answer
  
  for (int i=k; i<n; i++) {
    sum_b += ab[i].second - ab[i-k].second; // Update sum by adding current B_i and subtracting oldest B_i
    max_a = max(max_a, ab[i].first); // Update maximum A_i
    ans = min(ans, max_a * sum_b); // Update answer with new values
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t = 1;  cin >> t;
  while (t--) solve();
}