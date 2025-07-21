#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    vector<vector<pair<int, long long>>> adj(n + 1);
    
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    
    vector<long long> dist(n + 1, numeric_limits<long long>::max());
    dist[1] = A[0];
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({A[0], 1});
    
    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();
        if (d > dist[node]) continue;
        for (auto [next_node, weight] : adj[node]) {
            long long candidate_dist = d + weight + A[next_node - 1];
            if (candidate_dist < dist[next_node]) {
                dist[next_node] = candidate_dist;
                pq.push({candidate_dist, next_node});
            }
        }
    }
    
    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << (i < n ? " " : "");
    }
    
    return 0;
}