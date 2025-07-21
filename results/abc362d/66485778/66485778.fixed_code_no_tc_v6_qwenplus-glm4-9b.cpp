#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
vector<pair<int, int>> adj[200010]; // Adjacency list for the graph

int n, m;
int a[200010]; // vertex weights
int dist[200010]; // Minimum distance from vertex 1 to vertex i

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1}); // (distance, vertex)
    dist[1] = 0;

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[v] > d + w + a[v]) {
                dist[v] = d + w + a[v];
                pq.push({dist[v], v});
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dijkstra();

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}