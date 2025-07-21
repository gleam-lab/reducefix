#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Edge {
    int to, weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

vector<long long> dijkstra(int start, int n, const vector<vector<Edge>>& graph, const vector<int>& weights) {
    vector<long long> dist(n, numeric_limits<long long>::max());
    dist[start] = weights[start];
    
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({dist[start], start});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        long long d = pq.top().first;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (const auto& edge : graph[u]) {
            int v = edge.to;
            long long alt = dist[u] + weights[v] + edge.weight;
            
            if (alt < dist[v]) {
                dist[v] = alt;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<int> weights(n);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }
    
    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v; // Convert to 0-based index
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }
    
    vector<long long> result(n - 1);
    result = dijkstra(0, n, graph, weights);
    
    for (int i = 1; i < n; ++i) {
        cout << result[i - 1] << " ";
    }
    cout << endl;
    
    return 0;
}