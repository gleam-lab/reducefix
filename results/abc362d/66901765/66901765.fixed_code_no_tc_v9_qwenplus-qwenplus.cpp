#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;
const int MAXN = 200005;

vector<vector<pair<int, int>>> graph(MAXN); // adjacency list: {neighbor, edge_weight}
int A[MAXN]; // Vertex weights
int dist[MAXN]; // Shortest path distances from node 1

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[start] = A[start]; // Start includes the weight of the starting node
    pq.push({dist[start], start});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().second;
        pq.pop();
        
        if (dist[u] < d) continue; // Skip outdated entries
        
        for (auto& edge : graph[u]) {
            int v = edge.first;
            int edge_weight = edge.second;
            
            // Path to v through u:
            // Current path to u + edge weight + vertex weight of v
            int new_dist = dist[u] + edge_weight + A[v];
            
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({dist[v], v});
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        dist[i] = INF;
    }
    
    for (int i = 0; i < M; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        graph[u].push_back({v, b});
        graph[v].push_back({u, b});
    }
    
    dijkstra(1);
    
    for (int i = 2; i <= N; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";
    
    return 0;
}