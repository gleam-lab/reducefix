#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
using P = pair<ll, ll>;
const ll inf = 1e18;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  ll N, M;
  cin >> N >> M;

  vector<ll> A(N), B(M);
  vector<vector<pair<ll, ll>>> G(N);

  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }

  for (ll i = 0; i < M; ++i) {
    ll u, v, b;
    cin >> u >> v >> b;
    --u; --v; // Adjust indices to be zero-based
    G[u].emplace_back(v, b);
    G[v].emplace_back(u, b);
  }

  vector<ll> dist(N, inf);
  dist[0] = A[0]; // Starting point

  priority_queue<P, vector<P>, greater<>> pq;
  pq.emplace(dist[0], 0);

  while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();

    if (d > dist[u]) continue; // Skip outdated entries

    for (auto [v, w] : G[u]) {
      ll new_dist = d + w + A[v];

      if (new_dist < dist[v]) {
        dist[v] = new_dist;
        pq.emplace(new_dist, v);
      }
    }
  }

  for (ll i = 1; i < N; ++i) {
    cout << dist[i] << " ";
  }
  cout << "\n";

  return 0;
}