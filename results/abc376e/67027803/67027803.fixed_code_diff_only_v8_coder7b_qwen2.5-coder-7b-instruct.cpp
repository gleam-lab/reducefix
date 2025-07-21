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
  
  // Sort the pairs based on A_i
  sort(ab.begin(), ab.end());
  
  // Calculate the initial sum of B_i for the first K elements
  ll sum_b = 0;
  for (int i=0; i<k; i++) {
    sum_b += ab[i].second;
  }
  
  // Initialize the result with the initial product
  ll ans = ab[k-1].first * sum_b;
  
  // Sliding window approach to find the minimum product
  for (int i=k; i<n; i++) {
    // Update the sum by removing the smallest element of the previous window
    sum_b -= ab[i-k].second;
    // Add the largest element of the current window
    sum_b += ab[i].second;
    // Update the result with the new product if it's smaller
    ans = min(ans, ab[i].first * sum_b);
  }
  
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;  cin >> t;
  while (t--) solve();
}