#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
using P = pair<int, int>;
const ll inf = 1e18;

int main() {
  
  ll N, M;
  cin >> N >> M;
  
  vector<ll> A(N), B(M), ans(N, LLONG_MAX);
  vector<vector<pair<ll, ll>>> G(N);
  
  for(int i=0; i<N; i++) {
    cin >> A.at(i);
  }
  
  for(int i=0; i<M; i++) {
    int u, v;
    cin >> u >> v >> B.at(i);
    u--;
    v--;
    G.at(u).push_back(make_pair(v, B.at(i)));
    G.at(v).push_back(make_pair(u, B.at(i)));
  }
  
  priority_queue<P, vector<P>, greater<P>> pq;
  pq.push({A.at(0), 0});
  
  while(!pq.empty()) {
    auto [c, x] = pq.top(); pq.pop();
    
    if(c > ans[x]) continue;
    
    for(auto [v, d]: G.at(x)) {
      if(ans[v] > c + d + A.at(v)) {
        ans[v] = c + d + A.at(v);
        pq.push({ans[v], v});
      }
    }
  }
  
  for(int i=1; i<N; i++) {
    cout << ans[i] << " ";
  }
  
  return 0;
}