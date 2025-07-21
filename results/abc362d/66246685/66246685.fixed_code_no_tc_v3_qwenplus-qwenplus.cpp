#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
const ll INF = 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, M;
  cin >> N >> M;

  vector<ll> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  vector<vector<pll>> G(N); // Adjacency list: G[u] contains pairs (v, B_uv)
  for (int i = 0; i < M; ++i) {
    int u, v;
    ll b;
    cin >> u >> v >> b;
    u--; v--;
    G[u].push_back({v, b});
    G[v].push_back({u, b});
  }

  vector<ll> dist(N, INF);
  dist[0] = A[0]; // Start from node 0 with its value included

  priority_queue<pll, vector<pll>, greater<pll>> pq;
  pq.push({dist[0], 0});

  while (!pq.empty()) {
    auto [cost, u] = pq.top();
    pq.pop();

    if (cost > dist[u]) continue; // Skip outdated entries

    for (auto [v, b] : G[u]) {
      ll new_cost = cost + b + A[v]; // Include edge weight and destination vertex weight
      if (new_cost < dist[v]) {
        dist[v] = new_cost;
        pq.push({new_cost, v});
      }
    }
  }

  for (int i = 1; i < N; ++i) {
    cout << dist[i] << " ";
  }
  cout << '\n';

  return 0;
}