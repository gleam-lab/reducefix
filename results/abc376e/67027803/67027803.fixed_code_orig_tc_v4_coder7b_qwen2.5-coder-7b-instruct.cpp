#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e9 + 10;
const ll inf = 1LL << 60;

void solve() {
  int n, k; cin >> n >> k;
  vector<pair<ll, ll>> ab(n);
  for (int i = 0; i < n; i++) {
    cin >> ab[i].first;
    cin >> ab[i].second;
  }

  // Sort pairs based on the ratio A_i / B_i
  sort(ab.begin(), ab.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b) {
    return a.first * b.second < b.first * a.second;
  });

  ll ans = 0, max_a = 0;
  for (int i = 0; i < k; i++) {
    max_a = max(max_a, ab[i].first);
    ans += ab[i].second;
  }
  ans *= max_a;

  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1; cin >> t;
  while (t--) solve();
}