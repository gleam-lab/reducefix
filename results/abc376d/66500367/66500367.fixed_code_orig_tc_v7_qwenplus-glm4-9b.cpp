int bfs() {
    queue<pii> q;
    int max_depth = 0;
    for (int i = 1; i <= n; ++i) {
        if (!dep[i]) { // if node i is not visited
            dep[i] = 1;
            q.push({i, 0});
            while (!q.empty()) {
                int u = q.front().first, p = q.front().second;
                q.pop();
                for (auto v : g[u]) {
                    if (v != p) {
                        if (dep[v]) {
                            max_depth = max(max_depth, dep[v]);
                            return max_depth;
                        }
                        dep[v] = dep[u] + 1;
                        q.push({v, u});
                    }
                }
            }
        }
    }
    return max_depth;
}