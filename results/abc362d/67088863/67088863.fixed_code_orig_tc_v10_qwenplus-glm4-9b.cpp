if(ww + dist[v] < dist[u]){ // 'ww' is the edge's weight, 'dist[v]' is the distance to vertex 'v'
    dist[u] = ww; // Increment the distance by the edge's weight only
    pq.push({dist[u], u}); // Push the updated distance into the priority queue
}