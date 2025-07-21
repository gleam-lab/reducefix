#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
using P = pair<int, int>;
const ll inf = 1e18;

void dijkstra(const vector<VL>& g, const vector<ll>& w, int s, VL& dist) {
  int n = g.size();
  priority_queue<P, vector<P>, greater<>> pq;
  dist[s] = 0;
  pq.emplace(0, s);
  while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (dist[u] < d) continue;
    for (auto [v, c] : g[u]) {
      if (dist[v] > dist[u] + c + w[v]) {
        dist[v] = dist[u] + c + w[v];
        pq.emplace(dist[v], v);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<ll> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<vector<pair<int, ll>>> g(n);
  for (int i = 0; i < m; ++i) {
    int u, v, b;
    cin >> u >> v >> b;
    --u, --v;
    g[u].emplace_back(v, b);
    g[v].emplace_back(u, b);
  }

  vector<ll> dist(n, inf);
  dijkstra(g, a, 0, dist);

  for (int i = 1; i < n; ++i) {
    cout << dist[i] << " ";
  }
  cout << endl;

  return 0;
}