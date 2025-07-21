#include <bits/stdc++.h>
using namespace std;
#define INT int 

void solve() {
    int n, m;
    cin >> n >> m;
    vector<INT> a(n + 1);
    vector<pair<INT, pair<INT, INT>>> g(n + 1);
    for (INT i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (INT i = 1; i <= m; ++i) {
        INT u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }
    
    // Use Dijkstra's algorithm to find the shortest path from vertex 1 to all other vertices
    vector<INT> dist(n + 1, 1e18);
    priority_queue<pair<INT, pair<INT, INT>>, vector<pair<INT, pair<INT, INT>>>, greater<pair<INT, pair<INT, INT>>>> pq;
    pq.push({a[1], {1, 0}}); // Start from vertex 1 with initial distance as vertex weight
    dist[1] = a[1];

    while (!pq.empty()) {
        auto [t, {u, w}] = pq.top();
        pq.pop();

        if (w > dist[u]) {
            continue;
        }

        for (auto [v, c] : g[u]) {
            INT nextDist = dist[u] + c + a[v]; // Add vertex weight at the end of the path
            if (nextDist < dist[v]) {
                dist[v] = nextDist;
                pq.push({nextDist, {v, u}}); // Push with new distance
            }
        }
    }

    for (INT i = 2; i <= n; ++i) {
        cout << dist[i] << (i < n ? " " : "");
    }
}

int main() {
    solve();
    return 0;
}