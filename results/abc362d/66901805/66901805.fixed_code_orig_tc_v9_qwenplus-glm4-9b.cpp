void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});  // Push the source vertex with distance 0
    dis[1] = a[1];  // The distance from the source vertex to itself is its own weight
  
    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (dis[u] < current_dist) continue;  // Skip if we've already found a shorter path

        for (auto &edge : G[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dis[v] > dis[u] + weight) {
                dis[v] = dis[u] + weight;
                pq.push({dis[v], v});  // Push the new distance and vertex pair
            }
        }
    }
}