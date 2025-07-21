#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e9 + 10;
const ll inf = 1LL << 60;

void solve() {
  int n, k; cin >> n >> k;
  vector<pair<ll, ll>> ab(n);
  for (int i = 0; i < n; i++) cin >> ab[i].first;
  for (int i = 0; i < n; i++) cin >> ab[i].second;
  
  // Sort pairs by A in descending order
  sort(ab.begin(), ab.end(), greater<pair<ll, ll>>());
  
  priority_queue<ll, vector<ll>, greater<ll>> pq; // Min-heap for sum of B values
  ll heapSum = 0;
  
  // Initialize the heap with the first K-1 elements
  for (int i = 0; i < k - 1; i++) {
    pq.push(ab[i].second);
    heapSum += ab[i].second;
  }
  
  ll minExpressionVal = inf;
  
  // Process the remaining elements
  for (int i = k - 1; i < n; i++) {
    auto [a, b] = ab[i];
    // Calculate potential value if this A is chosen as max in the subset
    ll currentExpressionVal = (heapSum + b) * a;
    minExpressionVal = min(minExpressionVal, currentExpressionVal);
    
    // If the current B is greater than the top of the heap, replace and adjust the sum
    if (pq.top() > b) {
      heapSum -= pq.top();
      pq.pop();
      pq.push(b);
    }
  }
  
  cout << minExpressionVal << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t; cin >> t;
  while (t--) solve();
}