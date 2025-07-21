#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
using P = pair<ll, int>; // Change pair type to ll for storing path weights
const ll inf = 1000000000;

int main() {
  ll N, M;
  cin >> N >> M;

  vector<ll> A(N);
  vector<vector<P>> G(N); // Change type of edges to vector of pairs for storing edge weights
  priority_queue<P, vector<P>, greater<P>> pq; // Max-heap for Dijkstra's algorithm

  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }

  for (ll i = 0; i < M; ++i) {
    ll u, v, b;
    cin >> u >> v >> b;
    u--; v--; // Convert to 0-based index
    G[u].emplace_back(b, v);
    G[v].emplace_back(b, u);
  }

  pq.push({A[0] + A[0], 0}); // Push (weight, vertex) for vertex 1 with initial weight A[0] + A[0]
  vector<ll> dist(N, inf); // Distance from vertex 1 to all vertices initially set to inf
  dist[0] = A[0];

  while (!pq.empty()) {
    ll d = pq.top().first;
    ll v = pq.top().second;
    pq.pop();

    if (d > dist[v]) continue; // Skip if we already found a better path

    for (auto &u : G[v]) {
      ll cost = d - A[v] + u.first;
      if (cost < dist[u.second]) {
        dist[u.second] = cost;
        pq.push({cost, u.second});
      }
    }
  }

  // Output the minimum distances for vertices 2 to N
  for (ll i = 1; i < N; ++i) {
    cout << dist[i] << " ";
  }
  cout << "\n";

  return 0;
}