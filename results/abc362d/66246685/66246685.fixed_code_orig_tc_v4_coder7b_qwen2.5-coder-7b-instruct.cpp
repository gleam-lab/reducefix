#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
using P = pair<ll, ll>;
const ll inf = 1e18;

int main() {
  
  ll N, M;
  cin >> N >> M;
  
  vector<ll> A(N), B(M), ans(N, LLONG_MAX);
  vector<vector<pair<ll, ll>>> G(N);
  vector<bool> seen(N, false);

  for (int i = 0; i < N; ++i) {
    cin >> A.at(i);
  }

  for (int i = 0; i < M; ++i) {
    int u, v;
    cin >> u >> v >> B.at(i);
    u--;
    v--;
    G.at(u).push_back(make_pair(v, B.at(i)));
    G.at(v).push_back(make_pair(u, B.at(i)));
  }

  priority_queue<P, vector<P>, greater<P>> pq;
  pq.push({0, 0});

  while (!pq.empty()) {
    auto [dist, u] = pq.top();
    pq.pop();

    if (seen.at(u)) continue;
    seen.at(u) = true;

    for (auto [v, d] : G.at(u)) {
      if (dist + A.at(v) + d < ans.at(v)) {
        ans.at(v) = dist + A.at(v) + d;
        pq.push({ans.at(v), v});
      }
    }
  }

  for (int i = 1; i < N; ++i) {
    cout << ans.at(i) << " ";
  }
  cout << endl;

  return 0;
}