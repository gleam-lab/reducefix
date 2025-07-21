#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
using P = pair<int, int>;
const ll inf = 1e18; // Changed the infinity value to a larger number to handle large weights

int main() {
  ll N, M;
  cin >> N >> M;

  vector<ll> A(N), B(M), ans(N, LLONG_MAX);
  vector<vector<pair<ll, ll>>> G(N);

  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  for(int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v >> B[i];
    u--; // Adjusting indices to be zero-based
    v--;
    G[u].push_back({v, B[i]});
    G[v].push_back({u, B[i]});
  }

  priority_queue<P, vector<P>, greater<P>> pq;
  pq.push({A[0], 0}); // Starting from node 0 (vertex 1)

  while(!pq.empty()) {
    auto [cost, node] = pq.top();
    pq.pop();

    if(cost > ans[node]) continue; // Skip if we've found a cheaper path already

    for(auto [neighbor, edge_cost] : G[node]) {
      ll new_cost = cost + edge_cost + A[neighbor];

      if(new_cost < ans[neighbor]) {
        ans[neighbor] = new_cost;
        pq.push({new_cost, neighbor});
      }
    }
  }

  for(int i = 1; i < N; i++) {
    cout << ans[i] << " ";
  }

  return 0;
}