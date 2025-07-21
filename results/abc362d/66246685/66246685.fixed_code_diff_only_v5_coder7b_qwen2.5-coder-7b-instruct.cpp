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
  
  for(int i = 0; i < N; ++i){
    cin >> A.at(i);
  }
  
  for(int i = 0; i < M; ++i){
    int u, v;
    cin >> u >> v >> B.at(i);
    --u; --v;
    G.at(u).emplace_back(v, B.at(i));
    G.at(v).emplace_back(u, B.at(i));
  }
  
  priority_queue<P, vector<P>, greater<>> pq;
  pq.emplace(A.at(0), 0);
  
  while(!pq.empty()){
    auto [cost, node] = pq.top(); pq.pop();
    
    if(cost > dist[node]) continue;
    
    for(auto [neighbor, edge_cost]: G.at(node)){
      if(dist[neighbor] <= cost + edge_cost + A.at(neighbor)) continue;
      
      dist[neighbor] = cost + edge_cost + A.at(neighbor);
      pq.emplace(dist[neighbor], neighbor);
    }
  }
  
  for(int i = 1; i < N; ++i){
    cout << dist[i] << ' ';
  }
  
  return 0;
}