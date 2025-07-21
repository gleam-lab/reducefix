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
  sort(ab.rbegin(), ab.rend()); // Sort in descending order to make the max A_i easy to access

  // We need k elements with the maximum A_i and sum of B_i as small as possible
  // Start with the largest B_i values that will be included in the sum
  priority_queue<ll, vector<ll>, greater<ll>> pq; // Min-heap for the largest B_i values
  ll sum_b = 0;

  // Add the first k-1 elements to the min-heap (we keep k-1 smallest B_i for the sum)
  for (int i = 0; i < k - 1; ++i) {
    pq.push(ab[i].second);
    sum_b += ab[i].second;
  }

  ll min_value = inf;

  // Iterate from k-1 to n-1 to find the minimum possible value
  for (int i = k - 1; i < n; ++i) {
    min_value = min(min_value, (sum_b + ab[i].second) * ab[i].first);
    // We want to replace the smallest B_i in the sum with the current B_i
    if (!pq.empty() && pq.top() < ab[i].second) {
      sum_b += ab[i].second - pq.top();
      pq.pop();
      pq.push(ab[i].second);
    }
  }

  cout << min_value << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t = 1; cin >> t;
  while (t--) solve();
}