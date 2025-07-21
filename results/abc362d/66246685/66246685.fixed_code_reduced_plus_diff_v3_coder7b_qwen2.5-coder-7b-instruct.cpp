#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
using P = pair<int, int>;
const ll inf = 1000000000;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

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
    u--; v--;
    G.at(u).push_back(make_pair(v, B.at(i)));
    G.at(v).push_back(make_pair(u, B.at(i)));
  }

  priority_queue<P, vector<P>, greater<>> pq;
  pq.push({0, 0});

  while (!pq.empty()) {
    auto [dist, node] = pq.top(); pq.pop();

    if (seen.at(node)) continue;
    seen.at(node) = true;

    for (auto [neighbor, weight] : G.at(node)) {
      if (ans.at(neighbor) > dist + weight + A.at(neighbor)) {
        ans.at(neighbor) = dist + weight + A.at(neighbor);
        pq.push({ans.at(neighbor), neighbor});
      }
    }
  }

  for (int i = 1; i < N; ++i) {
    cout << ans.at(i) << " ";
  }
  cout << endl;

  return 0;
}