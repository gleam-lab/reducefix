#include <bits/stdc++.h>
using namespace std;
#define int long long 

int n, m;
vector<int> adj[200005]; // Adjacency list for efficient storage
vector<int> dist(200005, INT_MAX); // Distance array initialization

void dijkstra(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap for Dijkstra's
    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (dist[u] < 0) continue; // Negative distance indicates visited
        for (int v : adj[u]) {
            if (dist[v] > dist[u] + 1) { // 1 for edge weight
                dist[v] = dist[u] + 1;
                pq.push({dist[v], v});
            }
        }
    }
}

signed main() {
    scanf("%lld%lld", &n, &m);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        adj[u].push_back(v);
        adj[v].push_back(u); // Since it's undirected
    }

    dijkstra(1); // Calling dijkstra on vertex 1

    vector<int> result;
    for (int i = 2; i <= n; i++) {
        result.push_back(dist[i]);
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << (i < result.size() - 1 ? " " : "\n");
    }
    return 0;
}