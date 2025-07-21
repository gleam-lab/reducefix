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
  
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v >> B.at(i);
    u--;
    v--;
    G.at(u).push_back(make_pair(v, B.at(i)));
    G.at(v).push_back(make_pair(u, B.at(i)));
  }
  
  queue<pair<ll, ll>> q;
  q.push(make_pair(0, A.at(0))); // Start from vertex 1
  
  while (!q.empty()) {
    ll x = q.front().first;
    ll c = q.front().second;
    q.pop();
    
    for (auto [v, d] : G.at(x)) {
      if (c + d + A.at(v) < ans.at(v)) {
        ans.at(v) = c + d + A.at(v);
        q.push({v, c + d + A.at(v)});
      }
    }
  }
  
  for (int i = 1; i < N; i++) {
    cout << ans.at(i) << " "; // Print answer for each vertex except vertex 1
  }
  
  return 0;
}