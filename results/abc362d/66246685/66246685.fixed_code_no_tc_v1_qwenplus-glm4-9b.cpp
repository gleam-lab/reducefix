#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
using P = pair<ll, int>; // Change the type to ll for consistency and efficiency
const ll inf = 1000000000;

int main() {
  ll N, M;
  cin >> N >> M;

  VL A(N), B(M), ans(N, LLONG_MAX);
  VL adj[N];
  
  for(int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  
  for(int i = 0; i < M; ++i) {
    int u, v;
    cin >> u >> v >> B[i];
    u--; v--; // Convert to 0-based index
    adj[u].push_back({v, B[i]});
    adj[v].push_back({u, B[i]});
  }
  
  // Use a priority queue to find the shortest path using Dijkstra's algorithm
  priority_queue<P, VL, greater<P>> pq;
  pq.push({A[0], 0}); // Start from vertex 1 (index 0)

  while(!pq.empty()) {
    P cur = pq.top();
    pq.pop();
    int node = cur.second;
    ll dist = cur.first;

    // If we have already processed this node with a smaller distance, continue
    if (dist > ans[node]) continue;

    // Explore all neighbors
    for (auto& edge : adj[node]) {
      ll nextNode = edge.first;
      ll edgeWeight = edge.second;
      ll newDist = dist + edgeWeight + A[nextNode]; // Vertex weight is added here

      // Only consider this new path if it's better
      if (newDist < ans[nextNode]) {
        ans[nextNode] = newDist;
        pq.push({newDist, nextNode});
      }
    }
  }
  
  // Output the results for vertices 2 through N
  for (int i = 1; i < N; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}