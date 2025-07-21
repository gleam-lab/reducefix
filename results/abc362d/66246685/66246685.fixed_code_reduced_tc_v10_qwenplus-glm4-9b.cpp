#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
using P = pair<ll, ll>;
const ll inf = 1000000000;

int main() {
  ll N, M;
  cin >> N >> M;
  
  VL A(N), B(M), ans(N, inf);
  VL dist(N, inf);
  vector<vector<pair<ll, ll>>> G(N);

  for (ll i = 0; i < N; i++) {
    cin >> A[i];
  }

  for (ll i = 0; i < M; i++) {
    ll u, v;
    cin >> u >> v >> B[i];
    u--; v--;
    G[u].push_back({v, B[i]});
    G[v].push_back({u, B[i]});
  }

  priority_queue<P, VL, greater<P>> pq; // Min-heap
  pq.push({A[0], 0}); // Start from vertex 1 with its initial vertex weight
  dist[0] = A[0]; // We need to take the vertex weight into account

  while (!pq.empty()) {
    ll u = pq.top().second;
    ll d = pq.top().first;
    pq.pop();

    if (dist[u] < d) continue; // Skip if we already have a better distance

    for (auto [v, weight] : G[u]) {
      ll newDist = d + weight + A[v];
      if (dist[v] > newDist) {
        dist[v] = newDist;
        pq.push({newDist, v});
      }
    }
  }

  // Output the answers for i=2,3,...,N
  for (ll i = 1; i < N; i++) {
    cout << dist[i] << " ";
  }
  cout << endl;

  return 0;
}