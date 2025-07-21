#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;
const int INF = 1e18;

vector<int> g[N];
int dist[N];
int n, m, ans = INF;

void bfs() {
    queue<pair<int, int>> q; // {node, parent}
    q.push({1, -1});
    dist[1] = 0;

    while (!q.empty()) {
        auto [u, parent] = q.front();
        q.pop();

        for (int v : g[u]) {
            if (v == 1 && u != parent) {
                ans = min(ans, dist[u] + 1);
                continue;
            }
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push({v, u});
            }
        }
    }
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    fill(dist, dist + N, INF);
    bfs();

    if (ans != INF) cout << ans;
    else cout << -1;
    return 0;
}