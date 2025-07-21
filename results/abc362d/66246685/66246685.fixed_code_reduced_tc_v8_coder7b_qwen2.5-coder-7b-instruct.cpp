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
  
  priority_queue<P, vector<P>, greater<P>> pq;
  pq.push(make_pair(A.at(0), 0));
  
  while(!pq.empty()) {
    auto [c, x] = pq.top();
    pq.pop();
    if(seen.at(x)) continue;
    seen.at(x) = true;
    ans.at(x + 1) = min(ans.at(x + 1), c);
    
    for(auto [v, d]: G.at(x)) {
      pq.push({c + d + A.at(v), v});
    }
  }
  
  for(int i = 2; i <= N; i++) {
    cout << ans.at(i) << " ";
  }
  
  return 0;
}