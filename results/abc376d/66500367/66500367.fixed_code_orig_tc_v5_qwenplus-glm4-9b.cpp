int bfs() {
    queue<pii> q;
    q.push({1, 0});
    dep[1] = 1;
    while (!q.empty()) {
        int u = q.front().first, p = q.front().second;
        q.pop();
        for (auto v : g[u]) {
            if (v != p) {
                if (dep[v]) {
                    // If v is already visited, check if it's connected to the first node in its tree
                    if (dep[v] == dep[u] + 1 && !visited[v]) {
                        visited[v] = true;
                        q.push({v, u});
                        dep[v] = dep[u] + 1; // Ensure depth is updated
                    } else {
                        return dep[u]; // v is connected to the first node in its tree
                    }
                } else {
                    dep[v] = dep[u] + 1;
                    visited[v] = true;
                    q.push({v, u});
                }
            }
        }
    }
    return -1;
}