#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

#define INF numeric_limits<long long>::max()

typedef pair<long long, int> pi;

vector<vector<pair<int, long long>>> adj;

vector<long long> dijkstra(int start, int n) {
    vector<long long> dist(n + 1, INF);
    dist[start] = 0;
    
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        auto [distance, u] = pq.top();
        pq.pop();
        
        if (distance > dist[u]) continue;
        
        for (auto &[v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    adj.resize(n + 1);
    
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    vector<long long> result = dijkstra(1, n);
    
    for (int i = 2; i <= n; ++i) {
        cout << result[i] + a[i] << " ";
    }
    cout << endl;
    
    return 0;
}