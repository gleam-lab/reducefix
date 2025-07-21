#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
using P = pair<ll, ll>;
const ll inf = 1000000000;

int main() {

  ll N, M;
  cin >> N >> M;

  vector<ll> A(N), B(M);
  vector<vector<pair<ll, ll>>> G(N);
  vector<ll> ans(N, inf);
  vector<bool> seen(N, false);
  
  for (ll i = 0; i < N; i++) {
    cin >> A[i];
  }
  
  for (ll i = 0; i < M; i++) {
    ll u, v, b;
    cin >> u >> v >> b;
    u--; v--;
    G[u].push_back(make_pair(v, b));
    G[v].push_back(make_pair(u, b));
  }
  
  priority_queue<P, vector<P>, greater<P>> pq;
  pq.push({A[0], 0}); // Start from vertex 1 (index 0) with its weight
  
  while (!pq.empty()) {
    ll d = pq.top().second; // Current distance
    ll v = pq.top().first; // Current vertex
    pq.pop();
    
    if (seen[v]) continue;
    seen[v] = true;
    
    for (auto [to, weight] : G[v]) {
      if (seen[to]) continue;
      pq.push({to, d + weight + A[to]});
    }
  }
  
  for (ll i = 1; i < N; i++) {
    ans[i] = pq.top().second;
    pq.pop();
  }
  
  for (ll i = 1; i < N; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}