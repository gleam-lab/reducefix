while( !pq.empty() && pq.top()[0] <= i ) {
    auto a = pq.top(); pq.pop(); 
    for (int d = 0; d < 4; ++d) {
        int ny = a[1] + dy[d], nx = a[2] + dx[d];
        if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
        if (A[ny][nx] <= i) {
            used[ny][nx] = 1; // Mark as used
            pq.push({A[ny][nx], ny, nx}); // Add to priority queue
        }
    }
}