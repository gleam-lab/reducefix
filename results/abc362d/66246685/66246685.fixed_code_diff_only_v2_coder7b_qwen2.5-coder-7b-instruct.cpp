#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
using P = pair<int, int>;
const ll inf = 1000000000;

int main() {
  ll N, M;
  cin >> N >> M;
  
  vector<ll> A(N), B(M);
  vector<vector<pair<ll, ll>>> G(N);
  vector<ll> ans(N, inf);
  
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v >> B[i];
    u--;
    v--;
    G[u].push_back({v, B[i]});
    G[v].push_back({u, B[i]});
  }
  
  // Initialize the answer for the starting node
  ans[0] = A[0];
  
  queue<pair<ll, ll>> q;
  q.push({0, A[0]});
  
  while (!q.empty()) {
    ll x = q.front().first;
    ll c = q.front().second;
    q.pop();
    
    for (auto [v, d] : G[x]) {
      if (c + d + A[v] >= ans[v]) continue;
      ans[v] = c + d + A[v];
      q.push({v, ans[v]});
    }
  }
  
  for (int i = 1; i < N; i++) {
    cout << ans[i] << " ";
  }
  
  return 0;
}