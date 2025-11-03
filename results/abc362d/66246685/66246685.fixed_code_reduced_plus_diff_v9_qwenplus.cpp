#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
using P = pair<int, int>;
const ll inf = 1e18;

int main() {
  
  ll N, M;
  cin >> N >> M;
  
  vector<ll> A(N);
  vector<vector<pair<ll,ll>>> G(N);
  
  for(int i=0;i<N;i++){
    cin >> A.at(i);
  }
  
  for(int i=0;i<M;i++){
    int u, v;
    ll b;
    cin >> u >> v >> b;
    u--;
    v--;
    G.at(u).push_back(make_pair(v,b));
    G.at(v).push_back(make_pair(u,b));
  }
  
  vector<ll> dist(N, inf);
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
  
  dist[0] = A[0];
  pq.push({A[0], 0});
  
  while(!pq.empty()){
    auto [d, u] = pq.top();
    pq.pop();
    
    if(d > dist[u]) continue;
    
    for(auto [v, w] : G[u]){
      ll new_dist = d + w + A[v];
      if(new_dist < dist[v]){
        dist[v] = new_dist;
        pq.push({new_dist, v});
      }
    }
  }
  
  for(int i=1; i<N; i++){
    cout << dist[i] << " ";
  }
  cout << endl;
  
  return 0;
}