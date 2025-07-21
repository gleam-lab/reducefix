#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e9 + 10;
const ll inf = 1LL<<60;

void solve() {
  int n, k; cin >> n >> k;
  vector<pair<int, int>> ab(n);
  for (int i=0; i<n; i++) cin >> ab[i].first;
  for (int i=0; i<n; i++) cin >> ab[i].second;
  sort(ab.rbegin(), ab.rend()); // Sort in descending order to maximize product
  ll max_a = ab[k-1].first; // Maximum element in the subset
  ll sum_b = 0;
  for (int i=0; i<k; i++) sum_b += ab[i].second; // Sum of elements in the subset
  ll ans = max_a * sum_b; // Initial answer
  
  for (int i=k; i<n; i++) {
    sum_b -= ab[i-k].second; // Remove the smallest element from the sum
    sum_b += ab[i].second; // Add the next largest element to the sum
    ans = min(ans, max_a * sum_b); // Update the answer with the new product
  }
  
  cout << ans << '\n'; // Print the final answer
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;  cin >> t;
  while (t--) solve();
}