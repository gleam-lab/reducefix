#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
using P = pair<ll, ll>;
const ll inf = 1000000000;

int main() {
  ll N, M;
  cin >> N >> M;
  
  vector<ll> A(N);
  VL B(M);
  VL ans(N, inf); // Initialize all answers with infinity
  vector<vector<pair<ll, ll>>> G(N);
  
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }
  
  for (ll i = 0; i < M; ++i) {
    ll u, v, b;
    cin >> u >> v >> b;
    u--; v--; // Convert to zero-indexed
    G[u].push_back(P(v, b));
    G[v].push_back(P(u, b));
  }
  
  // Use a priority queue to always expand the least weight path first
  priority_queue<P, vector<P>, greater<P>> pq;
  pq.push(P(A[0], 0)); // Start from vertex 1, with initial vertex weight and no path weight
  ans[0] = A[0]; // The minimum path to vertex 1 is just its own weight
  
  while (!pq.empty()) {
    ll path_weight = pq.top().second;
    ll current_vertex = pq.top().first;
    pq.pop();
    
    // Process all adjacent vertices
    for (auto& [neighbor, edge_weight] : G[current_vertex]) {
      ll new_path_weight = path_weight + edge_weight;
      // If we find a better path to the neighbor, update and push to the queue
      if (new_path_weight < ans[neighbor]) {
        ans[neighbor] = new_path_weight;
        pq.push(P(neighbor, new_path_weight));
      }
    }
  }
  
  // Output the minimum path weights for all vertices from 2 to N
  for (ll i = 1; i < N; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}