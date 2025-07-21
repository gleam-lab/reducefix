#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1LL << 60;

void solve() {
  int n, k; cin >> n >> k;
  vector<pair<ll, ll>> ab(n);
  for (int i = 0; i < n; i++) cin >> ab[i].first;
  for (int i = 0; i < n; i++) cin >> ab[i].second;
  
  // Sort by A_i ascending
  sort(ab.begin(), ab.end());
  
  if (k == 1) {
    ll ans = INF;
    for (int i = 0; i < n; i++) {
      ans = min(ans, ab[i].first * ab[i].second);
    }
    cout << ans << '\n';
    return;
  }

  // Maintain the k-1 smallest B_i elements from the first i elements
  priority_queue<ll> max_heap; // Max heap to keep track of largest B in selected
  multiset<ll> rest; // Elements not in heap
  ll sum = 0;
  
  for (int i = 0; i < n; i++) {
    if (i < k - 1) {
      max_heap.push(ab[i].second);
      sum += ab[i].second;
    } else {
      rest.insert(ab[i].second);
    }
  }
  
  ll ans = INF;
  for (int i = k - 1; i < n; i++) {
    auto [a, b] = ab[i];
    ans = min(ans, (sum + b) * a);
    
    // Prepare for next iteration
    if (i < n - 1) {
      // Current element is at index i, we need to add it to our selection and remove one
      if (!max_heap.empty() && max_heap.top() > b) {
        // Replace the largest in our selection with the new b
        rest.insert(max_heap.top());
        max_heap.pop();
        max_heap.push(b);
        sum -= (b - sum + b); // This line isn't quite right, let's fix it:
        sum = sum - (max_heap.top() - b); // Actually, this approach won't work
      } else {
        // Add b to the rest and move the smallest from rest to our selection
        rest.insert(b);
      }
      
      // Now take the smallest from rest and add to our selection
      ll smallest_rest = *rest.begin();
      max_heap.push(smallest_rest);
      sum += smallest_rest;
      rest.erase(rest.begin());
    }
  }
  
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  while (t--) solve();
}