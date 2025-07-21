#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
using P = pair<ll, ll>;
const ll inf = 1000000000;

int main() {
  ll N, M;
  cin >> N >> M;

  vector<ll> A(N), ans(N, LLONG_MAX);
  vector<vector<pair<ll, ll>>> G(N);
  vector<bool> seen(N, false);

  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }

  for (ll i = 0; i < M; ++i) {
    ll u, v, b;
    cin >> u >> v >> b;
    u--; v--;
    G[u].push_back({v, b});
    G[v].push_back({u, b});
  }

  queue<P> q;
  q.push({A[0], A[0]}); // Start from vertex 1 with the weight of vertex 1 plus zero (no edges)
  
  while (!q.empty()) {
    ll x = q.front().first;
    ll c = q.front().second;
    q.pop();
    if (seen[x]) continue;
    seen[x] = true;
    ans[x] = c; // For vertex 1, it's already initialized, for others, it's set with the visited weight
    
    for (auto [v, d] : G[x]) {
      if (seen[v]) continue;
      q.push({v, c + d + A[v]});
    }
  }

  // Output the answers for vertices 2 to N
  for (ll i = 1; i < N; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;

  return 0;
}