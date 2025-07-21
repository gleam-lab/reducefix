// ... [rest of the code remains unchanged]

// Processing
for (int i = 0; i < Y; i++) {
    for (; !pq.empty(); ) {
        auto [h, x, y] = pq.top();
        if (h > i) { break; }
        pq.pop();
        // Check all adjacent sections
        for (int j = 0; j < 4; j++) {
            int dx = x + d[j][0], dy = y + d[j][1];
            if (dx < 0 || dx >= H || dy < 0 || dy >= W) {
                continue;
            }
            if (vis[dx][dy]) {
                continue;
            }
            vis[dx][dy] = true;
            pq.push({A[dx][dy], dx, dy});
        }
    }
    // Output the number of sections that have not been visited
    std::cout << (H * W - std::count(vis.begin(), vis.end(), false)) << "\n";
}

// ... [rest of the code remains unchanged]