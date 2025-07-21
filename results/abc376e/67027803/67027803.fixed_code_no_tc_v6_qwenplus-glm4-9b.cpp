#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e9 + 10;
const ll inf = 1LL<<60;

void solve() {
  int n, k; cin >> n >> k;
  vector<pair<ll, ll>> ab(n);
  for (int i = 0; i < n; i++) cin >> ab[i].first;
  for (int i = 0; i < n; i++) cin >> ab[i].second;
  sort(ab.begin(), ab.end());
  
  // If k equals 1, the answer is simply the maximum product of any A_i and B_i
  if (k == 1) {
    ll ans = inf;
    for (int i = 0; i < n; i++) {
      ans = min(ans, ab[i].first * ab[i].second);
    }
    cout << ans << '\n';
    return;
  }
  
  // We need to find the minimum value of the max element in the subset times the sum of that subset
  // We sort A in descending order and B in ascending order to optimize for the minimum sum
  vector<ll> B(n);
  for (int i = 0; i < n; i++) B[i] = ab[i].second;
  sort(B.begin(), B.end());
  
  // Priority queue to keep the sums of the top k-1 smallest elements in B
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    pq.push(B[i]);
    if (i < k - 1) sum += B[i];
  }
  
  ll ans = inf;
  for (int i = k - 1; i < n; i++) {
    auto [a, b] = ab[i];
    sum += b;
    pq.push(b);
    sum -= pq.top();
    pq.pop();
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