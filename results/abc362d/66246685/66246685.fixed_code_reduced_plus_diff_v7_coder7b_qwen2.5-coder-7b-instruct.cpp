#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
using P = pair<int, int>;
const ll inf = 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll N, M;
  cin >> N >> M;
  
  vector<ll> A(N), B(M);
  vector<vector<pair<ll, ll>>> G(N);
  vector<bool> seen(N, false);
  vector<ll> ans(N, LLONG_MAX);

  for(int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  for(int i = 0; i < M; ++i) {
    int u, v;
    cin >> u >> v >> B[i];
    --u, --v; // Adjust for 0-based indexing
    G[u].push_back({v, B[i]});
    G[v].push_back({u, B[i]});
  }

  // Function to perform BFS from source node s
  auto bfs = [&](ll s) {
    fill(seen.begin(), seen.end(), false);
    fill(ans.begin(), ans.end(), LLONG_MAX);
    queue<pair<ll, ll>> q;
    q.push({s, A[s]});
    ans[s] = A[s];

    while (!q.empty()) {
      ll x = q.front().first;
      ll c = q.front().second;
      q.pop();
      seen[x] = true;

      for (auto [v, d] : G[x]) {
        if (seen[v]) continue;
        if (ans[v] > c + d + A[v]) {
          ans[v] = c + d + A[v];
          q.push({v, ans[v]});
        }
      }
    }
  };

  // Perform BFS for each node starting from 1
  bfs(0); // Node 1 is at index 0

  // Print the results for nodes 2 to N
  for (int i = 1; i < N; ++i) {
    cout << ans[i] << " ";
  }

  return 0;
}