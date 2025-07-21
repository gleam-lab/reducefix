#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
using P = pair<ll, ll>; // Use ll for both first and second to ensure correct type for weights

const ll inf = 1000000000;

int main() {
  ll N, M;
  cin >> N >> M;
  
  VL A(N);
  VL ans(N, inf);
  vector<vector<P>> G(N); // Use P to store pairs of vertex and edge weight
  
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }
  
  for (ll i = 0; i < M; ++i) {
    ll u, v, b;
    cin >> u >> v >> b;
    u--; v--; // Adjust for 0-based index
    G[u].push_back({b, v});
    G[v].push_back({b, u});
  }
  
  // Start Dijkstra's algorithm from vertex 0
  priority_queue<P, vector<P>, greater<P>> pq;
  pq.push({A[0], 0}); // {current cost, vertex}
  ans[0] = 0;
  
  while (!pq.empty()) {
    ll current_cost = pq.top().first;
    ll u = pq.top().second;
    pq.pop();
    
    if (current_cost > ans[u]) continue; // Skip if we've already found a better path
    
    for (auto& [edge_weight, v] : G[u]) {
      ll new_cost = current_cost + edge_weight + A[v];
      if (new_cost < ans[v]) {
        ans[v] = new_cost;
        pq.push({new_cost, v});
      }
    }
  }
  
  // Output the minimum cost for paths to all vertices except the starting vertex
  for (ll i = 1; i < N; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}