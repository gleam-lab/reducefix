#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
using P = pair<int, int>;
const ll inf = 1e18;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  ll N, M;
  cin >> N >> M;

  vector<ll> A(N), B(M);
  vector<VL> G(N);
  vector<bool> seen(N, false);
  vector<VL> dist(N, vector<ll>(N, inf));

  for(int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  for(int i = 0; i < M; ++i) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    --u, --v;
    G[u].push_back(v);
    G[v].push_back(u);
    B[i] = w;
  }

  // Floyd-Warshall algorithm to find shortest paths between all pairs of nodes
  for(int k = 0; k < N; ++k) {
    for(int i = 0; i < N; ++i) {
      for(int j = 0; j < N; ++j) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  vector<ll> ans(N - 1, inf);
  priority_queue<P, vector<P>, greater<>> pq;

  for(int i = 0; i < N; ++i) {
    for(int j : G[i]) {
      pq.push({B[j], j});
    }
  }

  while(!pq.empty()) {
    auto [w, u] = pq.top(); pq.pop();

    if(seen[u]) continue;
    seen[u] = true;

    for(int v : G[u]) {
      if(seen[v]) continue;
      ans[v - 1] = min(ans[v - 1], A[u] + w + A[v] + dist[u][v]);
      pq.push({A[u] + w + A[v] + dist[u][v], v});
    }
  }

  for(int i = 0; i < N - 1; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;

  return 0;
}