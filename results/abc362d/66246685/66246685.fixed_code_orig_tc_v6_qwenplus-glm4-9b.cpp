#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
using P = pair<ll, ll>;
const ll inf = 1000000000;

int main() {
  ll N, M;
  cin >> N >> M;

  vector<ll> A(N), B(M), ans(N, LLONG_MAX);
  vector<vector<pair<ll, ll>>> G(N);
  vector<bool> seen(N, false);

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

  queue<pair<ll, ll>> q;
  q.push({0, A[0]});
  seen[0] = true;

  while (!q.empty()) {
    auto [x, c] = q.front();
    q.pop();

    for (auto [v, d] : G[x]) {
      if (seen[v]) continue;
      ans[v] = min(ans[v], c + d + A[v]);
      q.push({v, c + d + A[v]});
      seen[v] = true;
    }
  }

  for (int i = 1; i < N; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}