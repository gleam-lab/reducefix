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
    cin >> A.at(i);
  }
  
  for(int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v >> B.at(i);
    u--;
    v--;
    G.at(u).push_back(make_pair(v, B.at(i)));
    G.at(v).push_back(make_pair(u, B.at(i)));
  }
  
  // Priority queue to hold pairs of {weight, node}
  priority_queue<P, vector<P>, greater<P>> pq;
  pq.push({A.at(0), 0});
  
  while(!pq.empty()) {
    ll x = pq.top().second;
    ll c = pq.top().first;
    pq.pop();
    seen.at(x) = true;
    
    if(c > ans.at(x)) continue; // Skip if already found a shorter path
    
    for(auto [v, d] : G.at(x)) {
      if(seen.at(v)) continue;
      ans.at(v) = min(ans.at(v), c + d + A.at(v));
      pq.push({ans.at(v), v});
    }
  }
  
  for(int i = 1; i < N; i++) {
    cout << ans.at(i) << " ";
  }
  
  return 0;
}