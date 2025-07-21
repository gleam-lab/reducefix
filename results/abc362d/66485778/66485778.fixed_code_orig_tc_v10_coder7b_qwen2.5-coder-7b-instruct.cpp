#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<long long, int> PII;
typedef vector<PII> VPII;
typedef vector<VPII> Graph;

void dijkstra(const Graph &graph, int source, vector<long long> &dist) {
    int n = graph.size();
    dist.assign(n, LLONG_MAX);
    dist[source] = 0;
    
    priority_queue<PII, VPII, greater<PII>> pq;
    pq.push({0, source});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto &[v, weight] : graph[u]) {
            long long new_dist = dist[u] + weight + graph[v][u].second;
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    Graph graph(n + 1);
    for (int i = 1; i <= m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        graph[u].push_back({v, b});
        graph[v].push_back({u, b});
    }
    
    vector<long long> dist;
    dijkstra(graph, 1, dist);
    
    for (int i = 2; i <= n; ++i) {
        cout << dist[i] + a[i] << " ";
    }
    cout << "\n";
    
    return 0;
}