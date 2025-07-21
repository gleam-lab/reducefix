#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
using P = pair<int, int>;
const ll inf = 1e18;

int main() {
  ll N, M;
  cin >> N >> M;
  
  vector<ll> A(N), B(M);
  vector<vector<pair<ll,ll>>> G(N);
  
  for(int i=0;i<N;i++){
    cin >> A.at(i);
  }
  
  for(int i=0;i<M;i++){
    int u, v;
    cin >> u >> v >> B.at(i);
    u--; v--;
    G.at(u).push_back(make_pair(v,B.at(i)));
    G.at(v).push_back(make_pair(u,B.at(i)));
  }
  
  vector<ll> dist(N, inf);
  priority_queue<P, vector<P>, greater<P>> pq;
  
  dist[0] = A[0];
  pq.push(P(A[0], 0));
  
  while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (dist[u] != d) continue;
    
    for (auto [v, w] : G[u]) {
      ll nd = d + A[v] + w;
      if (nd < dist[v]) {
        dist[v] = nd;
        pq.push(P(nd, v));
      }
    }
  }
  
  for (int i=1; i<N; ++i) {
    cout << dist[i] << ' ';
  }
  
  return 0;
}