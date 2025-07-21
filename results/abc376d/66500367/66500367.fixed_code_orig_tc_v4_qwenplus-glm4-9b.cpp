int bfs() {
    queue<pii> q;
    q.push({1, 0});
    dep[1] = 1;
    while (!q.empty()) {
        int u = q.front().first, p = q.front().second;
        q.pop();
        for (auto v : g[u])
            if (v != p) {
                dep[v] = dep[u] + 1;
                q.push({v, u});
            }
    }
    return dep[1]; // Return the depth of the root node
}