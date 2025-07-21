#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
using P = pair<ll, int>;
const ll inf = 1000000000LL;

int main() {
  ll N, M;
  cin >> N >> M;
  
  vector<ll> A(N), B(M);
  vector<vector<pair<int, ll>>> G(N);
  
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  
  for (int i = 0; i < M; ++i) {
    int u, v;
    ll b;
    cin >> u >> v >> b;
    u--; v--;
    G[u].push_back({v, b});
    G[v].push_back({u, b});
  }
  
  // Dijkstra's algorithm to find the minimum path to vertex 1 from all vertices
  priority_queue<P, vector<P>, greater<P>> pq;
  vector<ll> dist(N, inf);
  pq.push({0, 0});  // Start from vertex 1 with cost 0
  dist[0] = 0;
  
  while (!pq.empty()) {
    auto [cost, node] = pq.top();
    pq.pop();
    if (dist[node] < cost) continue;
    
    for (auto &e : G[node]) {
      ll nextNode = e.first;
      ll weight = e.second + A[nextNode];
      if (dist[nextNode] > cost + weight) {
        dist[nextNode] = cost + weight;
        pq.push({dist[nextNode], nextNode});
      }
    }
  }

  // Output the minimum path weights for vertices 2 to N
  vector<ll> result(N - 1);
  for (int i = 1; i < N; ++i) {
    result[i - 1] = dist[i];
  }
  
  for (auto &d : result) {
    cout << d << " ";
  }
  cout << endl;
  
  return 0;
}