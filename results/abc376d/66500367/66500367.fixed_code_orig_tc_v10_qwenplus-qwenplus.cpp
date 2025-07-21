#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int N = 200005;
vector<vector<int>> g(N);
int n, m;

int bfs(int start, vector<bool>& visited) {
    vector<int> dep(n + 1, 0);
    queue<pii> q;
    q.push({start, -1});
    dep[start] = 0;
    visited[start] = true;

    int min_cycle = INT_MAX;

    while (!q.empty()) {
        auto [u, parent] = q.front();
        q.pop();

        for (int v : g[u]) {
            if (!visited[v]) {
                visited[v] = true;
                dep[v] = dep[u] + 1;
                q.push({v, u});
            } else if (v != parent) {
                // Found a back edge
                min_cycle = min(min_cycle, dep[u] + dep[v] + 1);
            }
        }
    }

    return (min_cycle == INT_MAX) ? -1 : min_cycle;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);
    int ans = INT_MAX;

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            int res = bfs(i, visited);
            if (res != -1)
                ans = min(ans, res);
        }
    }

    cout << ((ans == INT_MAX) ? -1 : ans) << '\n';

    return 0;
}