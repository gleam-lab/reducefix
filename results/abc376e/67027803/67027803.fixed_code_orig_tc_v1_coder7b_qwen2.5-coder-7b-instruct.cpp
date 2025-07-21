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
  
  // Initialize variables
  ll ans = inf;
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  ll sum = 0;
  
  // Calculate initial sum of first k-1 elements in B
  for (int i = 0; i < k-1; i++) {
    pq.push(b[i]);
    sum += b[i];
  }
  
  // Iterate through array A to find the minimum product
  for (int i = 0; i <= n-k; i++) {
    pq.push(b[i+k-1]);
    sum += b[i+k-1];
    
    ans = min(ans, (a[n-1-i] * sum));
    
    // Remove the smallest element in the window from the sum
    sum -= pq.top();
    pq.pop();
  }
  
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;  cin >> t;
  while (t--) solve();
}