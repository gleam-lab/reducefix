#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
using P = pair<ll, int>;
const ll inf = 1000000000;

int main() {
  ll N, M;
  cin >> N >> M;
  
  vector<ll> A(N), B(M);
  vector<vector<pair<ll, int>>> G(N);
  vector<ll> dist(N, inf);
  
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  
  for(int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v >> B[i];
    u--;
    v--;
    G[u].push_back({v, B[i]});
    G[v].push_back({u, B[i]});
  }
  
  priority_queue<P, vector<P>, greater<P>> pq;
  pq.push({A[0], 0});
  
  while(!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    
    if(d > dist[u]) continue;
    
    for(auto [v, w] : G[u]) {
      ll new_d = d + A[v] + w;
      if(new_d < dist[v]) {
        dist[v] = new_d;
        pq.push({new_d, v});
      }
    }
  }
  
  for(int i = 1; i < N; i++) {
    cout << dist[i] << " ";
  }
  
  return 0;
}