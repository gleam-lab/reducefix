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
  
  for(int i = 0; i < N; ++i){
    cin >> A[i];
  }
  
  for(int i = 0; i < M; ++i){
    int u, v;
    cin >> u >> v >> B[i];
    --u, --v; // Adjusting indices since C++ uses 0-based indexing
    G[u].emplace_back(v, B[i]);
    G[v].emplace_back(u, B[i]);
  }
  
  // Initialize answer for vertex 1
  ans[0] = A[0];
  
  // BFS setup
  queue<ll> q;
  vector<bool> seen(N, false);
  q.push(0);
  seen[0] = true;
  
  while (!q.empty()) {
    ll current = q.front();
    q.pop();
    
    for (auto [neighbor, cost] : G[current]) {
      if (seen[neighbor]) continue;
      
      // Calculate new cost to neighbor
      ll new_cost = ans[current] + cost + A[neighbor];
      
      // Update answer and enqueue if new cost is lower
      if (new_cost < ans[neighbor]) {
        ans[neighbor] = new_cost;
        q.push(neighbor);
      }
    }
  }
  
  // Output results excluding the first element
  for (int i = 1; i < N; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
  
  return 0;
}