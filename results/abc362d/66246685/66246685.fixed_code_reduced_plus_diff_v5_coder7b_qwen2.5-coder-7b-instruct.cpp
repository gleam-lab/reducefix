#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int to, weight;
};

vector<Edge> adj[200001];

void dijkstra(int start, int n, vector<long long>& dist) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto& e : adj[u]) {
            int v = e.to, w = e.weight;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    vector<long long> A(n+1), dist(n+1, LLONG_MAX);
    
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }
    
    for (int i = 0; i < m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        adj[u].emplace_back(v, b);
        adj[v].emplace_back(u, b);
    }
    
    // Dijkstra from node 1
    dijkstra(1, n, dist);
    
    for (int i = 2; i <= n; ++i) {
        cout << dist[i] + A[i] << " ";
    }

    return 0;
}