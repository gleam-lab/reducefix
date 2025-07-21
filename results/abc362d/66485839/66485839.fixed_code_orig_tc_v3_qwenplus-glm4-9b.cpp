#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 200010;
vector<pair<int, int>> adj[N]; // adj[i] stores pairs (neighbor, edge_weight)
int dist[N]; // dist[i] stores the minimum weight from vertex 1 to vertex i

// Comparator for priority_queue
struct Compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return dist[a.first] > dist[b.first];
    }
};

void dijkstra(int n) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    dist[1] = 1; // weight of the first vertex is its own weight
    pq.push({1, 1}); // Use {vertex, current_dist} as pairs
    while (!pq.empty()) {
        auto front = pq.top();
        pq.pop();
        int u = front.first;
        int d = front.second;
        
        for (auto& e : adj[u]) {
            int v = e.first;
            int weight = e.second + dist[u]; // total weight if we go through u to v
            if (weight < dist[v]) {
                dist[v] = weight;
                pq.push({v, weight});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> dist[i]; // Input the weight of each vertex
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Since the graph is undirected
    }

    dijkstra(n); // Run Dijkstra's algorithm

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    
    return 0;
}