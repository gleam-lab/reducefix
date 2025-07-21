#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;

const ll INF = 1e18;

struct Edge {
    int to, cost;
};

void dijkstra(const vector<vector<Edge>>& adj, const vector<ll>& weights, int start, vector<ll>& dist) {
    int n = adj.size();
    dist.assign(n, INF);
    dist[start] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        
        for (auto [v, w] : adj[u]) {
            ll new_dist = d + weights[v] + w;
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<ll> weights(n);
    for (int i = 0; i < n; ++i) cin >> weights[i];
    
    vector<vector<Edge>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v; // Adjusting for zero-based indexing
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    vector<ll> dist(n);
    dijkstra(adj, weights, 0, dist);
    
    for (int i = 1; i < n; ++i) {
        cout << dist[i] + weights[i] << " ";
    }
    cout << endl;
    
    return 0;
}