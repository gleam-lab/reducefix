#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e5 + 10;
constexpr int INF = 1e18;
int n, m;
vector<int> a(N), dist(N, INF);
vector<bool> visited(N);

struct Edge {
    int u, v, w;
};

vector<Edge> edges;
vector<vector<pair<int, int>>> adj(N);

void dijkstra(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[src] = a[src];
    pq.push({dist[src], src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (visited[u]) continue;
        visited[u] = true;

        for (auto &[v, w] : adj[u]) {
            if (dist[v] > dist[u] + a[v] + w) {
                dist[v] = dist[u] + a[v] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dijkstra(1);

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}