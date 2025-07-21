#include<bits/stdc++.h>
using namespace std;
#define int long long 

vector<pair<int, int>> G[200005]; // Adjacency list
int dis[200005], a[200005], n, m; // Distance, vertex weights, graph dimensions

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap
    pq.push({0, start}); // Push start vertex with initial distance 0
    dis[start] = a[start]; // Set initial distance of start vertex
    
    while (!pq.empty()) {
        int u = pq.top().second; // Current vertex
        pq.pop();
        
        for (auto [v, w] : G[u]) { // Explore neighbors
            int cost = dis[u] + w + a[v]; // Calculate cost to neighbor
            if (cost < dis[v]) { // If cost is less than current distance
                dis[v] = cost; // Update distance
                pq.push({dis[v], v}); // Push updated distance and neighbor
            }
        }
    }
}

int main() {
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; // Read vertex weights
    }
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        G[u].push_back({v, w}); // Add edge to adjacency list
        G[v].push_back({u, w}); // Add symmetric edge
    }
    
    memset(dis, 0x3f, sizeof(dis)); // Initialize distance array
    dijkstra(1); // Run Dijkstra's algorithm from vertex 1
    
    for (int i = 2; i <= n; i++) {
        cout << dis[i] << ' '; // Output minimum weight path for each vertex
    }
    cout << '\n';
    return 0;
}