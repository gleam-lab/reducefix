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
  sort(ab.begin(), ab.end());
  
  ll ans = inf;
  ll sumB = 0; // This will store the sum of B values for the top k elements
  
  // Calculate the sum of B for the top k elements
  for (int i = n - 1; i >= n - k; --i) {
    sumB += ab[i].second;
    // Calculate the expression with the current max A and sum of B
    ans = min(ans, ab[i].first * sumB);
  }
  
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  while (t--) solve();
}