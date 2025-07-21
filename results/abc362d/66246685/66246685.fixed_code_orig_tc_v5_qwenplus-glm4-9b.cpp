#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18; // A large enough constant to initialize distances

int main() {
  ll N, M;
  cin >> N >> M;
  vector<ll> A(N), B(M);
  vector<vector<pair<ll, ll>>> G(N); // Adjacency list for the graph
  vector<ll> ans(N, INF); // Distance array initialized with INF
  
  // Read vertex weights
  for (ll i = 0; i < N; i++) {
    cin >> A[i];
  }
  
  // Read edges and construct graph
  for (ll i = 0; i < M; i++) {
    ll u, v, b;
    cin >> u >> v >> b;
    u--; v--; // Convert to zero-indexed
    G[u].push_back({v, b});
    G[v].push_back({u, b});
  }
  
  // Use priority queue to process vertices
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
  pq.push({0, 0}); // Process vertex 1 (zero-indexed)
  ans[0] = 0; // Distance to itself is 0
  
  while (!pq.empty()) {
    ll dist = pq.top().first;
    ll cur = pq.top().second;
    pq.pop();
    
    if (dist > ans[cur]) {
      continue; // Skip if already processed with a better distance
    }
    
    for (auto &edge : G[cur]) {
      ll next = edge.first;
      ll edge_weight = edge.second;
      ll new_dist = dist + A[next] + edge_weight;
      
      if (new_dist < ans[next]) {
        ans[next] = new_dist;
        pq.push({new_dist, next});
      }
    }
  }
  
  // Output the result, skipping vertex 1
  for (ll i = 1; i < N; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  
  return 0;
}