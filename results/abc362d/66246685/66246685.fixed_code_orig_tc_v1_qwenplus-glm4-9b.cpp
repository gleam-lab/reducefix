#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
using P = pair<ll, int>; // The first element is the distance, the second element is the vertex index.
const ll inf = 1e18;

int main() {
  ll N, M;
  cin >> N >> M;
  
  VL A(N);
  VL dist(N, inf); // Distance array.
  vector<vector<pair<int, ll>>> G(N); // Graph represented as adjacency list.
  
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }
  
  for (ll i = 0; i < M; ++i) {
    int u, v;
    ll b;
    cin >> u >> v >> b;
    u--; v--; // Convert to 0-based index.
    G[u].push_back({v, b});
    G[v].push_back({u, b});
  }
  
  priority_queue<P, VL, greater<P>> q;
  q.push({A[0], 0});
  dist[0] = A[0];
  
  while (!q.empty()) {
    auto [cost, u] = q.top();
    q.pop();
    
    for (auto [v, b] : G[u]) {
      ll new_cost = cost + b + A[v];
      if (new_cost < dist[v]) {
        dist[v] = new_cost;
        q.push({new_cost, v});
      }
    }
  }
  
  VL ans(N - 1);
  for (ll i = 1; i < N; ++i) {
    ans[i - 1] = dist[i];
  }
  
  for (auto &a : ans) {
    cout << a << " ";
  }
}