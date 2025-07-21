#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<long long, int> pii;

void dijkstra(const vector<vector<pii>>& adj, vector<long long>& dist, int start) {
    int n = adj.size();
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    dist[start] = adj[start][0].second;
    pq.push({dist[start], start});
    
    while (!pq.empty()) {
        auto [current_dist, current_node] = pq.top();
        pq.pop();
        
        if (current_dist > dist[current_node])
            continue;
        
        for (auto [neighbor, weight] : adj[current_node]) {
            if (dist[current_node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[current_node] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<long long> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    vector<vector<pii>> adj(n + 1);
    for (int i = 1; i <= m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        adj[u].push_back({v, b + a[v]});
        adj[v].push_back({u, b + a[u]});
    }

    vector<long long> dist(n + 1, LLONG_MAX);
    dijkstra(adj, dist, 1);

    for (int i = 2; i <= n; ++i)
        cout << dist[i] << " ";

    return 0;
}