#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;

vector<int> g[N];
int n, m;

int bfs() {
    vector<int> dist(n + 1, -1);
    queue<pair<int, int>> q; // {node, parent}
    q.push({1, -1});
    dist[1] = 0;
    int ans = 1e18;

    while (!q.empty()) {
        auto [u, parent] = q.front();
        q.pop();

        for (int v : g[u]) {
            if (v == parent) continue;
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push({v, u});
            } else {
                ans = min(ans, dist[u] + dist[v] + 1);
            }
        }
    }
    return ans;
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = bfs();
    if (ans != (int)1e18) cout << ans;
    else cout << -1;
    return 0;
}