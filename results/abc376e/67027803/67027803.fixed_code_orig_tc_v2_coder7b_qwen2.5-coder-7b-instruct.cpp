#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e9 + 10;
const ll inf = 1LL<<60;

void solve() {
  int n, k; cin >> n >> k;
  vector<ll> ab(n);
  for (int i=0; i<n; i++) cin >> ab[i];
  vector<ll> cd(n);
  for (int i=0; i<n; i++) cin >> cd[i];
  
  // Sort arrays A and B
  sort(ab.begin(), ab.end());
  sort(cd.rbegin(), cd.rend());
  
  // Calculate the result using the sorted arrays
  ll ans = 0;
  for (int i=0; i<k; i++) {
    ans = max(ans, ab[i] * cd[i]);
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;  cin >> t;
  while (t--) solve();
}