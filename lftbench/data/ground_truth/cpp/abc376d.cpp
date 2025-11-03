#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

using Graph = vector<vector<long long>>;

int main() {
  long long n, m;
  cin >> n >> m;

  Graph g(n + 1);
  Graph lg(n + 1);

  for (long long i = 0; i < m; i++) {
    long long a, b;
    cin >> a >> b;

    g[a].push_back(b);
    lg[b].push_back(a);
  }

  vector<long long> dist = vector<long long>(n + 1, -1);
  dist[1] = 0;

  queue<int> que;
  que.push(1);

  while (!que.empty()) {
    int v = que.front();
    que.pop();

    for (auto next_v : g[v]) {
      if (dist[next_v] != -1) {
        continue;
      }

      dist[next_v] = dist[v] + 1;
      que.push(next_v);
    }
  }

  vector<long long> ldist = vector<long long>(n + 1, -1);
  ldist[1] = 0;

  queue<int> lque;
  lque.push(1);

  while (!lque.empty()) {
    int v = lque.front();
    lque.pop();

    for (auto next_v : lg[v]) {
      if (ldist[next_v] != -1) {
        continue;
      }

      ldist[next_v] = ldist[v] + 1;
      lque.push(next_v);
    }
  }

  long long ans = -1;
  for (long long i = 2; i <= n; i++) {
    if (dist[i] != -1 && ldist[i] != -1) {
      long long tmp = dist[i] + ldist[i];
      if (ans == -1) {
        ans = tmp;
      } else {
        ans = min(ans, tmp);
      }
    }
  }

  cout << ans << endl;
}
