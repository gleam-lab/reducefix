#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int j = 0; j < m; ++j) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Initialize distances with a large value
    vector<long long> dist(n + 1, 1e10);
    // Set the distance to the starting vertex (vertex 1)
    dist[1] = a[0]; 

    // Priority queue to process vertices in increasing order of their distances
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    q.push({ dist[1], 1 });

    // Process the graph
    while (!q.empty()) {
        auto cur = q.top();
        q.pop();

        long long d = cur.first;
        int ver = cur.second;

        // Process all adjacent vertices
        for (auto &nxt : adj[ver]) {
            int adjVer = nxt.first;
            long long adjDis = nxt.second + a[adjVer - 1];  // Consider vertex weight
            if (d + adjDis < dist[adjVer]) {
                dist[adjVer] = d + adjDis;
                q.push({ dist[adjVer], adjVer });
            }
        }
    }

    // Output the distances from vertex 1 to all other vertices
    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;
}