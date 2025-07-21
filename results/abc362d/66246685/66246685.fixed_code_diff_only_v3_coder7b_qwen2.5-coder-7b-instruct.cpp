#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
using P = pair<int, int>;
const ll inf = 1000000000;

int main() {
  
  ll N, M;
  cin >> N >> M;
  
  vector<ll> A(N), B(M), ans(N, LLONG_MAX);
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
    G[u].push_back({v, B[i]});
    G[v].push_back({u, B[i]});
  }
  
  priority_queue<P, vector<P>, greater<>> pq;
  pq.push({A[0], 0});
  
  while(!pq.empty()) {
    auto [c, x] = pq.top();
    pq.pop();
    
    if(seen[x]) continue;
    seen[x] = true;
    
    ans[x] = min(ans[x], c);
    
    for(auto [v, d] : G[x]) {
      if(seen[v]) continue;
      pq.push({c + d + A[v], v});
    }
  }
  
  for(int i = 1; i < N; i++) {
    cout << ans[i] << " ";
  }
  
  return 0;
}