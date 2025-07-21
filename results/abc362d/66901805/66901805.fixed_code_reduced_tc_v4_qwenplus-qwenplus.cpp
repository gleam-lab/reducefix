#include<bits/stdc++.h>
using namespace std;
#define int long long 

const int MAXN = 200005;
vector<pair<int, int>> G[MAXN]; // adjacency list: {neighbor, edge_weight}
int A[MAXN]; // vertex weights
int dist[MAXN]; // distance from node 1
bool visited[MAXN];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    // Start from node 1 with initial cost A[1]
    dist[start] = A[start];
    pq.push({dist[start], start});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int current_dist = pq.top().first;
        pq.pop();
        
        if (visited[u]) continue;
        visited[u] = true;
        
        for (auto [v, edge_cost] : G[u]) {
            // When reaching v from u:
            // - we already have A[u] in the path
            // - we add edge_cost and A[v]
            // So total cost to reach v is dist[u] + edge_cost + A[v]
            if (!visited[v] && dist[v] > dist[u] + edge_cost + A[v]) {
                dist[v] = dist[u] + edge_cost + A[v];
                pq.push({dist[v], v});
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        dist[i] = numeric_limits<int>::max(); // Initialize distances to infinity
    }
    
    for (int i = 0; i < M; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        G[u].push_back({v, b});
        G[v].push_back({u, b});
    }
    
    dijkstra(1);
    
    for (int i = 2; i <= N; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;
    
    return 0;
}