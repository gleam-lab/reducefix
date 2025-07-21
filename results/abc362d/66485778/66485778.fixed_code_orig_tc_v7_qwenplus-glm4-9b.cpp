struct Node {
    int x, d; // d should be the total weight
    bool operator < (const Node& u) const {
        return d > u.d; // Use '>' for a max-heap and '<' for a min-heap
    }
};

void solve2() {
    // ... [rest of the inputs are correct]

    pq.emplace(1, d[1] = a[1]); // Ensure that the first element is correctly initialized

    while (pq.size()) {
        auto [x, w] = pq.top();
        pq.pop();
        if (vis[x]) continue;
        vis[x] = true;
        for (const auto& [y, dw] : g[x]) {
            if (d[x] + dw + a[y] < d[y]) {
                d[y] = d[x] + dw + a[y];
                pq.emplace(y, d[y]);
            }
        }
    }

    // ... [output the results]
}