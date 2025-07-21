#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e18;

vector<vector<pair<int, int>>> graph(200005); // graph[u] contains pairs (v, edge_weight)
int A[200005]; // Vertex weights
int dist[200005];
bool visited[200005];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[start] = A[start];
    pq.push({dist[start], start});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int current_dist = pq.top().first;
        pq.pop();
        
        if (visited[u]) continue;
        visited[u] = true;
        
        for (auto [v, edge_weight] : graph[u]) {
            int new_dist = current_dist + edge_weight + A[v];
            if (!visited[v] && new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({new_dist, v});
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