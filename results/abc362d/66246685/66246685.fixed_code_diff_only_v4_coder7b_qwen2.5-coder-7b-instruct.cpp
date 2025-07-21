#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
using P = pair<int, int>;
const ll inf = 1000000000;

int main() {
  
  ll N, M;
  cin >> N >> M;
  
  vector<ll> A(N), B(M), dist(N, LLONG_MAX);
  vector<vector<pair<ll, ll>>> G(N);
  vector<bool> seen(N, false);
  
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  
  for(int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v >> B[i];
    u--;
    v--;
    G[u].push_back(make_pair(v, B[i]));
    G[v].push_back(make_pair(u, B[i]));
  }
  
  // Initialize the distance from node 0 to itself
  dist[0] = A[0];
  
  priority_queue<P, vector<P>, greater<P>> pq;
  pq.push({dist[0], 0});
  
  while(!pq.empty()) {
    ll d = pq.top().first;
    ll x = pq.top().second;
    pq.pop();
    
    if(seen[x]) continue;
    seen[x] = true;
    
    for(auto [v, w]: G[x]) {
      if(dist[v] > d + A[v] + w) {
        dist[v] = d + A[v] + w;
        pq.push({dist[v], v});
      }
    }
  }
  
  for(int i = 1; i < N; i++) {
    cout << dist[i] << " ";
  }
  
  return 0;
}