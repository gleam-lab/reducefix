#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
using P = pair<ll, ll>;
const ll inf = 1000000000;

int main() {
  ll N, M;
  cin >> N >> M;
  
  vector<ll> A(N), B(M), ans(N, inf);
  vector<vector<pair<ll, ll>>> G(N);
  
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  
  for (int i = 0; i < M; i++) {
    ll u, v, b;
    cin >> u >> v >> b;
    u--; v--; // Convert to zero-based index
    G[u].push_back({v, b});
    G[v].push_back({u, b});
  }
  
  // Start Dijkstra's algorithm from vertex 0
  priority_queue<P, vector<P>, greater<P>> pq; // Min-heap
  pq.push({A[0], 0}); // Initial position is vertex 0, cost is A[0]
  
  while (!pq.empty()) {
    ll cur_cost = pq.top().second;
    ll cur_vertex = pq.top().first;
    pq.pop();
    
    if (cur_cost > ans[cur_vertex]) continue;
    
    for (auto [next_vertex, edge_cost] : G[cur_vertex]) {
      ll new_cost = cur_cost + edge_cost + A[next_vertex];
      if (new_cost < ans[next_vertex]) {
        ans[next_vertex] = new_cost;
        pq.push({next_vertex, new_cost});
      }
    }
  }
  
  for (int i = 1; i < N; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}