#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e9 + 10;
const ll inf = 1LL << 60;

void solve() {
  int n, k; cin >> n >> k;
  vector<pair<ll, ll>> ab(n);
  for (int i = 0; i < n; i++) cin >> ab[i].first;
  for (int i = 0; i < n; i++) cin >> ab[i].second;
  
  // We want to maximize A_i for the K smallest B_i, so we sort A first.
  sort(ab.begin(), ab.end(), greater<pair<ll, ll>>());
  
  // If k == 1, we are forced to take the smallest B_i and the maximum A_i.
  if (k == 1) {
    ll ans = inf;
    for (int i = 0; i < n; i++) {
      ans = min(ans, ab[i].first * ab[i].second);
    }
    cout << ans << '\n';
    return;
  }
  
  // We will use a priority queue to keep the K largest B_i values.
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  ll sum = 0;
  
  // We add the first K-1 elements into the priority queue.
  for (int i = 0; i < n && i < k; i++) {
    pq.push(ab[i].second);
    sum += ab[i].second;
  }
  
  ll ans = inf;
  
  // Now we iterate over the remaining elements. We skip the smallest one
  // each time because we want to maximize A_i for the K smallest B_i.
  for (int i = k - 1; i < n; i++) {
    ans = min(ans, (sum + pq.top()) * ab[i].first);
    if (i == n - 1) break; // No need to process further if we are at the last element.
    sum += ab[i].second - pq.top(); // Replace the smallest B_i in the priority queue.
    pq.pop();
    pq.push(ab[i].second); // Push the new B_i.
  }
  
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t; cin >> t;
  while (t--) solve();
}