#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
using P = pair<ll, ll>;
const ll inf = 1000000000;

int main() {
  
  ll N, M;
  cin >> N >> M;
  
  VL A(N), B(M), ans(N + 1, LLONG_MAX);
  VL dist(N + 1, LLONG_MAX); // Use an extra space for 1-based indexing
  VL edges(N + 1); // To store the edges
  
  for (ll i = 1; i <= N; ++i) {
    cin >> A[i];
  }
  
  for (ll i = 1; i <= M; ++i) {
    ll u, v, b;
    cin >> u >> v >> b;
    edges[u].push_back({v, b});
    edges[v].push_back({u, b});
  }
  
  vector<bool> visited(N + 1, false);
  queue<ll> q; // Use 1-based indexing
  q.push(1);
  dist[1] = A[1];
  visited[1] = true;
  
  while (!q.empty()) {
    ll x = q.front();
    q.pop();
    
    for (auto [v, d] : edges[x]) {
      if (visited[v]) continue;
      dist[v] = dist[x] + d + A[v]; // Use the correct formula
      visited[v] = true;
      q.push(v);
    }
  }
  
  for (ll i = 2; i <= N; ++i) {
    cout << dist[i] << " ";
  }
  cout << endl;
  
  return 0;
}