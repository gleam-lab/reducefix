#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define INF 0x3f3f3f3f3f3f3f3f

struct Edge {
    int to, weight;
};

vector<Edge> adj[200010];

void dijkstra(int src, int n, vector<LL>& dist) {
    priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>>> pq;
    dist[src] = 0;
    pq.push({0, src});
    
    while (!pq.empty()) {
        auto [current_dist, u] = pq.top();
        pq.pop();
        
        if (current_dist > dist[u]) continue;
        
        for (auto& [v, weight] : adj[u]) {
            if (dist[v] > dist[u] + weight + weight) { // Adjusted for edge weight consideration
                dist[v] = dist[u] + weight + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<LL> weights(n + 1);
    for (int i = 1; i <= n; ++i) cin >> weights[i];

    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight}); // Graph is undirected
    }

    vector<LL> dist_to_start(n + 1, INF);
    dijkstra(1, n, dist_to_start);

    for (int i = 2; i <= n; ++i) {
        cout << dist_to_start[i] + weights[i] << " ";
    }
    cout << "\n";

    return 0;
}