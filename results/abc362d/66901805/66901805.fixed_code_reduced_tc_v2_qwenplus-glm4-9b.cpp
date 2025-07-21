#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<pair<int,pair<int, int>>>G[200005]; // Changed to store edge and vertex weights
int dist[200005];
int a[200005];
int n, m;
void dijkstra(int u) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap for Dijkstra's
    pq.push({0, u}); // Start with vertex 1
    while (!pq.empty()) {
        int curDist = pq.top().first;
        int curVert = pq.top().second;
        pq.pop();
        if (curDist > dist[curVert]) continue; // Skip if already visited with a better distance
        for (auto &edge : G[curVert]) {
            int v = edge.first;
            int edgeWeight = edge.second;
            if (curDist + edgeWeight < dist[v]) {
                dist[v] = curDist + edgeWeight;
                pq.push({dist[v], v});
            }
        }
    }
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    memset(dist, 0x3f, sizeof(dist)); // Initialize distances to infinity
    dijkstra(1); // Run Dijkstra's from vertex 1
    for (int i = 2; i <= n; ++i) {
        // Subtract vertex weight to get the minimum path weight
        cout << dist[i] - a[i] << ' ';
    }
    cout << '\n';
    return 0;
}