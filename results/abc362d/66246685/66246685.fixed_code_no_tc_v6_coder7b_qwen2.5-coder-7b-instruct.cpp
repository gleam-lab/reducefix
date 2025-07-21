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

  // Initialize the distance from vertex 1 to itself as 0
  ans[0] = 0;
  queue<pair<ll, ll>> q;
  q.push(make_pair(0, A.at(0)));

  while (!q.empty()) {
    ll x = q.front().first;
    ll c = q.front().second;
    q.pop();

    // If we have already processed this node, skip it again
    if (seen.at(x)) continue;
    seen.at(x) = true;

    for (auto [v, d] : G.at(x)) {
      if (seen.at(v)) continue;
      // Update the answer only if the new path is shorter
      if (ans[v] > c + d + A[v]) {
        ans[v] = c + d + A[v];
        q.push({v, c + d + A[v]});
      }
    }
  }

  for (int i = 1; i < N; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}