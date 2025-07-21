#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e9 + 10;
const ll inf = 1LL << 60;

void solve() {
  int n, k; cin >> n >> k;
  vector<pair<ll, ll>> ab(n);
  for (int i = 0; i < n; i++) cin >> ab[i].first >> ab[i].second;
  
  // Sort based on the product of B_i and A_i in descending order
  sort(ab.begin(), ab.end(), [&](const pair<ll, ll>& a, const pair<ll, ll>& b) {
    return a.second * b.first > b.second * a.first;
  });

  // Priority queue to keep track of the sum of B_i for the current subset
  priority_queue<ll, vector<ll>, greater<>> pq;
  ll sum = 0;
  for (int i = 0; i < k; i++) {
    pq.push(ab[i].second);
    sum += ab[i].second;
  }

  ll ans = sum * ab[k-1].first;

  // Iterate through the remaining elements to find the best subset
  for (int i = k; i < n; i++) {
    auto [a, b] = ab[i];
    sum += b;
    pq.push(b);

    // Remove the smallest element from the priority queue to maintain the subset size
    sum -= pq.top();
    pq.pop();

    // Calculate the new potential answer
    ans = min(ans, sum * a);
  }

  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1; cin >> t;
  while (t--) solve();
}