#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
using P = pair<int, int>;
const ll inf = LLONG_MAX;

int main() {
  
  ll N, M;
  cin >> N >> M;
  
  vector<ll> A(N), B(M), ans(N, inf);
  vector<vector<pair<ll, ll>>> G(N);
  
  for(int i = 0; i < N; ++i){
    cin >> A[i];
  }
  
  for(int i = 0; i < M; ++i){
    int u, v;
    cin >> u >> v >> B[i];
    --u; --v;
    G[u].emplace_back(v, B[i]);
    G[v].emplace_back(u, B[i]);
  }
  
  priority_queue<P, vector<P>, greater<>> pq;
  pq.emplace(A[0], 0);
  
  while(!pq.empty()){
    auto [cost, node] = pq.top(); pq.pop();
    if(cost > ans[node]) continue;
    for(auto [neighbor, weight] : G[node]){
      if(ans[neighbor] > cost + A[neighbor] + weight){
        ans[neighbor] = cost + A[neighbor] + weight;
        pq.emplace(ans[neighbor], neighbor);
      }
    }
  }
  
  for(int i = 1; i < N; ++i){
    cout << ans[i] << " ";
  }
  
  return 0;
}