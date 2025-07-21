#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int v, w;
};

struct Graph {
    int V;
    vector<vector<Edge>> adj;
    
    Graph(int V) : V(V), adj(V) {}
    
    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
};

vector<long long> dijkstra(Graph& g, int src) {
    vector<long long> dist(g.V, LLONG_MAX);
    dist[src] = g.adj[src][0].w; // Assuming weight of the edge to itself is 0
    
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({dist[src], src});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        long long d = pq.top().first;
        pq.pop();
        
        if (d != dist[u])
            continue;
        
        for (auto& edge : g.adj[u]) {
            int v = edge.v;
            long long newDist = d + edge.w;
            
            if (newDist < dist[v]) {
                dist[v] = newDist;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    Graph g(n);
    
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v; // Convert to zero-based indexing
        g.addEdge(u, v, w);
    }
    
    vector<long long> result = dijkstra(g, 0); // Start from vertex 1 (0-based index)
    
    for (int i = 1; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << "\n";
    
    return 0;
}