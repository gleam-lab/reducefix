#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, long long> pii;

struct Graph {
    int n;
    vector<vector<pii>> adj;
    vector<long long> dist;

    Graph(int n) : n(n), adj(n), dist(n, numeric_limits<long long>::max()) {}

    void addEdge(int u, int v, long long w) {
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    void dijkstra(int start) {
        dist[start] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.emplace(0, start);

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (auto &[v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Graph g(n);
    vector<int> weights(n);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
        g.dist[i] += weights[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        --u; --v;
        g.addEdge(u, v, w);
    }

    g.dijkstra(0);

    for (int i = 1; i < n; ++i) {
        cout << g.dist[i] << " ";
    }
    cout << "\n";

    return 0;
}