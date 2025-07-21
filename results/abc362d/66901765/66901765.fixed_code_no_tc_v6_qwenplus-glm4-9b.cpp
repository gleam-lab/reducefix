#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<pair<int, int>> G[200005];
int dis[200005], a[200005], n, m;
vector<int> adj[200005];

void dijkstra(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    dis[src] = a[src]; // Include the vertex weight in the initial distance
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (dis[u] != INT_MAX) continue; // Skip processed vertices
        for (auto v : adj[u]) {
            int weight = dis[u] + a[v] + 1; // Include edge weight and vertex weight
            if (weight < dis[v]) {
                dis[v] = weight;
                pq.push({dis[v], v});
            }
        }
    }
}

signed main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // Initialize distances to a large value
    for (int i = 1; i <= n; i++) {
        dis[i] = INT_MAX;
    }
    
    dijkstra(1);
    
    for (int i = 2; i <= n; i++) {
        if (dis[i] == INT_MAX) {
            cout << "INF "; // If no path is found, output INF
        } else {
            cout << dis[i] << " ";
        }
    }
    cout << "\n";
    return 0;
}