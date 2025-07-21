#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
using P = pair<int, int>;
const ll inf = 1e18;

int main() {
  ll N, M;
  cin >> N >> M;
  
  vector<ll> A(N), B(M), dist(N, LLONG_MAX);
  vector<vector<pair<ll, ll>>> G(N);
  
  for(int i=0; i<N; i++) cin >> A[i];
  
  for(int i=0; i<M; i++){
    int u, v; 
    cin >> u >> v >> B[i];
    u--; 
    v--;
    G[u].push_back({v, B[i]});
    G[v].push_back({u, B[i]});
  }
  
  priority_queue<P, vector<P>, greater<>> pq;
  pq.push({A[0], 0});
  
  while(!pq.empty()) {
    auto [cost, node] = pq.top(); 
    pq.pop();
    
    if(dist[node] <= cost) continue; 
    dist[node] = cost;
    
    for(auto [next_node, edge_cost]: G[node]) {
      pq.push({cost + A[next_node] + edge_cost, next_node});
    }
  }
  
  for(int i=1; i<N; i++) {
    cout << dist[i] << " ";
  }
  cout << endl;
}