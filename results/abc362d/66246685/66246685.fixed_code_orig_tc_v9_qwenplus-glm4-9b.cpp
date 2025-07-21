#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
using P = pair<ll, ll>;
const ll inf = 1000000000;

int main() {
  ll N, M;
  cin >> N >> M;
  
  VL A(N), B(M);
  VL dist(N, inf);
  vector<VL> G(N);
  
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  
  for (int i = 0; i < M; i++) {
    ll u, v, b;
    cin >> u >> v >> b;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
    B[i] = b;
  }
  
  queue<ll> q;
  q.push(0); // starting vertex 1
  dist[0] = A[0];
  
  while (!q.empty()) {
    ll u = q.front();
    q.pop();
    
    for (ll v : G[u]) {
      ll edgeWeight = B[dist[u]]; // get edge weight based on the current path
      ll newDist = dist[u] + edgeWeight + A[v]; // calculate new distance
      if (newDist < dist[v]) { // only consider this path if it's better
        dist[v] = newDist;
        q.push(v);
      }
    }
  }
  
  for (ll i = 1; i < N; i++) {
    cout << dist[i] << " ";
  }
  cout << endl;
  
  return 0;
}