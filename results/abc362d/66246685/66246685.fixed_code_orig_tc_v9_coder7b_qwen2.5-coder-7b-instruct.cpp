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

  vector<ll> A(N + 1), B(M + 1);
  vector<VL> G(N + 1);
  vector<bool> seen(N + 1, false);

  for (ll i = 1; i <= N; ++i) {
    cin >> A[i];
  }

  for (ll i = 1; i <= M; ++i) {
    cin >> B[i];
  }

  for (ll i = 1; i <= M; ++i) {
    ll u, v;
    cin >> u >> v;
    G[u].emplace_back(v, B[i]);
    G[v].emplace_back(u, B[i]);
  }

  vector<ll> ans(N + 1, inf);
  ans[1] = A[1];

  priority_queue<P, vector<P>, greater<>> pq;
  pq.emplace(0, 1);

  while (!pq.empty()) {
    auto [cost, u] = pq.top();
    pq.pop();

    if (seen[u]) continue;
    seen[u] = true;

    for (auto [v, d] : G[u]) {
      if (ans[v] > cost + A[v] + d) {
        ans[v] = cost + A[v] + d;
        pq.emplace(cost + A[v] + d, v);
      }
    }
  }

  for (ll i = 2; i <= N; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;

  return 0;
}